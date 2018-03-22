//
// Created by Zachary Aries on 2018-02-25.
//

#include "Client.h"

using std::string;

Client::Client(int server_port, string server_name, size_t block_size) {
    this->server_port = server_port;
    this->block_size = block_size;

    //const char* server_name = "localhost";

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;

    // creates binary representation of server name
    // and stores it as sin_addr
    //inet_pton: convert IPv4 and IPv6 addresses from text to binary form
    inet_pton(AF_INET, server_name.c_str(), &server_address.sin_addr);

    server_address.sin_port = htons(server_port);

    this->server_address_len = sizeof(server_address);
}

void Client::get_file(std::string file_name) {
    Debug::printl("\n=====================\n Initializing Client \n=====================");

    open_connection();

    std::cout << "\nAttempting Download\n====================\n"
              << "server:\tlocalhost\n"
              << "file:\t" << file_name <<"\n\n";

    ssize_t out_len, in_len;

    char buffer[block_size + header_size];
    bzero(buffer, sizeof(buffer));

    // create GET string
    string get_request = "GET " + file_name;
    in_len = process_file(sockfd, get_request, file_name);

    // close the socket
    close(sockfd);
}

void Client::open_connection() {
    // open socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        Debug::printl("Error! Could not create client socket...");
        exit(EXIT_FAILURE);
    }
    Debug::printl("Client socket created.");
}

ssize_t Client::process_file(int fd, std::string file_request, string file_name) {

    unsigned short seq = 0;
    unsigned short expected_seq = 1;

    int timeout_count = 0;
    string output_path =  OUTPUT_ROOT + file_name;
    bool write_started = false;
    string out_msg = file_request;

    // outbox and inbox buffers
    char outbuff[block_size + header_size], inbuff[block_size + header_size];

    bool done = false;
    while (!done) {
        bzero(outbuff, sizeof(outbuff));

        // create message to send, attach sequence number
        Protocol::create_message(seq, outbuff, out_msg.c_str(), 0, (int)out_msg.length());

        Debug::printl("\nSending Message\nseq: "
                      + std::to_string(seq)
                      + "\nmsg: " + out_msg + "\n");

        if(!Debug::sim_pkt_loss()){
            ssize_t out_len = sendto(fd, outbuff, (file_request.length() + header_size), 0,
                                     (struct sockaddr *) &server_address, server_address_len);
        }

        if(seq > 7) {
            seq = 0;
            expected_seq = 1;
        }

        pid_t pid1;
        int mypipe[2];

        /* Create the pipe. */
        if (pipe(mypipe)) {
            fprintf(stderr, "Pipe failed.\n");
            return EXIT_FAILURE;
        }

        /* Create the child process. */
        pid1 = fork();
        if (pid1 == (pid_t) 0) {
            /* This is the child process.
             Close other end first. */
            sleep(TIMEOUT);

            ssize_t status = -2;

            close(mypipe[0]);
            write(mypipe[1], &status, sizeof(ssize_t));
            close(mypipe[1]);

            exit(EXIT_SUCCESS);
        } else if (pid1 < (pid_t) 0) {
            /* The fork failed. */
            fprintf(stderr, "Fork failed.\n");
            return EXIT_FAILURE;
        } else {
            pid_t pid2;

            pid2 = fork();

            if (pid2 == (pid_t) 0) {

                ssize_t status;
                bzero(inbuff, sizeof(inbuff));
                ssize_t in_len = recvfrom(fd, inbuff, block_size + header_size, 0, nullptr, nullptr);

                int resp_seq = Protocol::get_sequence(inbuff);
                string recv_msg = Protocol::get_message(inbuff, in_len);

                if (recv_msg.compare(0, 3, "DNE") == 0 && resp_seq == 0) {
                    status = -3;
                } else if (recv_msg.compare(0, 3, "FIN") == 0 && resp_seq == 9) {
                    status = -4;
                } else if (in_len > 0){
                    if(resp_seq == expected_seq){
                        status = in_len;

                        std::cout << "received: seg " << std::to_string(resp_seq) << ", "
                                  << std::to_string(in_len - 1) << " bytes\n";
                        Debug::printl("msg: " + recv_msg + "\n");
                    } else {
                        status = -1;
                    }
                } else {
                    status = -5;
                }

                close(mypipe[0]);
                write(mypipe[1], &status, sizeof(ssize_t));
                close(mypipe[1]);

                if (status > 0) {
                    if (!write_started) {
                        remove(output_path.c_str());
                    }

                    std::ofstream outfile;
                    outfile.open (output_path.c_str(), std::fstream::out | std::fstream::app);
                    outfile.write(recv_msg.c_str(), recv_msg.length());

                    outfile.close();
                }

                exit(EXIT_SUCCESS);
            } else if (pid2 > (pid_t) 0) {

                ssize_t recv_status = 0;

                close(mypipe[1]);
                read(mypipe[0], &recv_status, sizeof(ssize_t));
                close(mypipe[0]);

                if (recv_status == -2) {
                    kill(pid2, SIGTERM);
                } else {
                    kill(pid1, SIGTERM);
                }

                wait(nullptr);

                if( recv_status > 0 ){
                    if(!write_started){
                        write_started = true;
                    }
                    seq ++;
                    expected_seq ++;
                    timeout_count = 0;

                    out_msg = "ACK";
                } else if (recv_status == -1){
                    std::cout << "Wrong Sequence! Expected: " << std::to_string(expected_seq) << std::endl;
                } else if (recv_status == -2){
                    std::cout << "Error! Timeout, resending data...\n";
                    timeout_count ++;

                    if (timeout_count >= MAXTIMEOUT){
                        // create and send error message
                        string error = "FIN Error! Timeout error, could not download \"" + file_name + "\"";
                        send_msg(fd, error, server_address, server_address_len);

                        std::cout << "Error! Max Timeout, ending data transfer...\n";

                        // return -1 to indicate an error occurred
                        return -1;
                    }
                } else if (recv_status == -3){
                    std::cout << "Error! File does not exist...\n";
                    return -1;
                } else if (recv_status == -4){
                    Debug::printl("Finished!");
                    return 1;
                } else {
                    Debug::printl("Error! Unknown Error, ending data transfer...");
                    return -2;
                }
            }
        }
    }
    return -2;
}

ssize_t Client::send_msg(int fd, std::string message, struct sockaddr_in client_address, socklen_t client_address_len) {

    // create out buffer
    char out_buff[message.length() + header_size];

    // create protocol message
    bzero(out_buff, sizeof(out_buff));
    Protocol::create_message(0, out_buff, message.c_str(), 0, (int)message.length());

    // send error message to client
    ssize_t out_len = sendto(fd, out_buff, sizeof(out_buff), 0,
                         (struct sockaddr *)&client_address,
                         client_address_len);

    return out_len;
}
