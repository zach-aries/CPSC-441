//
// Created by Zachary Aries on 2018-02-25.
//

#include "Server.h"
#include <string>

int Server::sockfd;
using std::string;

Server::Server(int port, size_t block_size) {
    this->port = port;
    this->block_size = block_size;

    // socket address used for the server
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;

    // htons: host to network short: transforms a value in host byte
    // ordering format to a short value in network byte ordering format
    server_address.sin_port = htons(this->port);

    // htons: host to network long: same as htons but to long
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
}

void Server::start() {
    std::cout << "\n=====================\n Initializing Server \n=====================\n";

    // initiate connection
    open_connection();
    Debug::printl("Server started succesfully.");

    run = true;
    while (run) {

        // client info
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);

        // set up and wait for connection from client
        char buffer[512];
        bzero(buffer, sizeof(buffer));

        std::cout << "\nWaiting for request...\n";

        // read content into buffer from an incoming client
        int in_len = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                          (struct sockaddr *)&client_address,
                          &client_address_len);

        int prc_len = process_request(sockfd, buffer, in_len,client_address, client_address_len);
    }

    close(sockfd);
    Debug::printl("Socket closed");
    exit(EXIT_SUCCESS);
}

int Server::process_request(int fd, char *in_buffer, size_t in_buff_len, struct sockaddr_in client_address,
                            socklen_t client_address_len) {

    char buffer[512];
    ssize_t out_len, in_len;

    // extract message from buffer
    string file_req = Protocol::get_message(in_buffer, in_buff_len);

    // if the message is not a GET request send an error message
    // and go back to wait_for_request to listen for another client
    if ( file_req.compare(0,3,"GET") != 0){
        // create and send error message
        string error = "FIN Error! Could not process \"" + file_req + "\"";
        send_msg(sockfd, error, client_address, client_address_len);

        Debug::printl("\nError! Unknown request, sending error message to client...\nmsg: "
                      + error);

        // return -1 to indicate an error occurred
        return -1;
    }

    // get file name from request and create path using default path to files
    string file_name (file_req, 4, file_req.length() - 4);
    string file_path = FILE_ROOT + file_name;

    // save client ip and port
    // inet_ntoa prints user friendly representation of the ip address
    string client_name;
    client_name = string(inet_ntoa(client_address.sin_addr)) + ":" + std::to_string(ntohs(client_address.sin_port));
    std::cout << "Client: " << client_name << ", requesting: " << file_name << std::endl << std::endl;

    // check to see if file exists, if not send a Does Not Exist response
    if (!FileHelper::file_exists(file_path)){
        // create and send error message
        string error = "DNE";
        send_msg(sockfd, error, client_address, client_address_len);

        Debug::printl("\nError! File does not exist, sending error message to client...\nmsg: "
                      + error);

        // return -2 to indicate an error occurred, -2 = DNE
        return -2;
    }

    Debug::printl("File exists, sending file...");

    int file_size = get_file_size(file_path);
    char file_buffer[file_size];

    if (!recv_file(file_buffer, file_path)){
        // create and send error message
        string error = "FIN Error! Could not process \"" + file_req + "\"";
        send_msg(sockfd, error, client_address, client_address_len);

        Debug::printl("\nError! Unknown request, sending error message to client...\nmsg: "
                      + error);

        // return -1 to indicate an error occurred
        return -1;
    }

    int index = 0;
    int remaining_file_size = file_size;
    unsigned short seq = 0;

    while (remaining_file_size > 0) {

        // calculate size of message to send using protocol algorithm
        // and send 8 times
        int msg_size = Protocol::calc_block_size(remaining_file_size);
        int timeout_count = 0;

        seq = 1;
        while (seq < 9) {

            // if there is no more data to send, pad with spaces
            if (remaining_file_size <= 0) {
                file_buffer[index] = ' ';
                file_buffer[index + 1] = '\0';
            }

            // outbox and inbox buffers
            char outbuff[block_size + header_size], inbuff[64];
            bzero(outbuff, sizeof(outbuff));
            bzero(inbuff, sizeof(inbuff));

            in_len = send_recv(sockfd, seq, index, file_buffer, msg_size, inbuff,
                               client_address, client_address_len);

            // if in_len >=, good ack received
            // if in_len == -1, bad ack received
            // if in_len == -2, timeout
            // if in_len == -3, unknown error
            if (in_len >= 0){
                seq++;
                remaining_file_size -= msg_size;
                index += msg_size;
                timeout_count = 0;
            } else if (in_len == -1){
                std::cout << "Error! Wrong sequence ACK, resending data...\n";
            } else if (in_len == -2){
                std::cout << "Error! Timeout, resending data...\n";
                timeout_count ++;

                if (timeout_count >= MAXTIMEOUTS){
                    // create and send error message
                    string error = "FIN Error! Timeout error, could not process \"" + file_req + "\"";
                    send_msg(sockfd, error, client_address, client_address_len);

                    std::cout << "Error! Max Timeout, ending data transfer...\n";

                    // return -1 to indicate an error occurred
                    return -1;
                }
            } else {
                // create and send error message
                string error = "FIN Error! Could not process \"" + file_req + "\"";
                send_msg(sockfd, error, client_address, client_address_len);

                std::cout << "Error! Unknown error, ending data transfer...\n";

                // return -1 to indicate an error occurred
                return -1;
            }
        }
    }

    // create FIN message c-string
    string fin_str = "FIN";

    // create protocol message
    bzero(buffer, sizeof(buffer));
    Protocol::create_message(seq, buffer, fin_str.c_str(), 0, fin_str.length());

    // send error message to client
    out_len = sendto(sockfd, buffer, (fin_str.length() + header_size), 0,
                     (struct sockaddr *)&client_address,
                     client_address_len);

    Debug::printl("\nSent Finish\n============\nseq: "
                  + std::to_string(seq)
                  + "\nmsg: " + fin_str);
    return 1;
}

ssize_t Server::send_recv(int fd, unsigned short seq, int index, const char *msg, int msg_len, char * inbuff,
                     struct sockaddr_in client_address, socklen_t client_address_len){

    // create buffer to send message
    char buffer[block_size + header_size];
    bzero(buffer, sizeof(buffer));

    // create message to send, attach sequence number
    Protocol::create_message(seq, buffer, msg, index, msg_len);

    if( seq != 0 ){
        std::cout << "sent: seg " << seq << ", " << msg_len << " bytes\n";
    } else {
        Debug::printl("sent: seg " + std::to_string(seq) + ", " + std::to_string(msg_len) + " bytes");
    }

    Debug::printl("msg: " + string(msg));

    if(!Debug::sim_pkt_loss()) {
        ssize_t out_len = sendto(fd, buffer, (msg_len + header_size), 0,
                                 (struct sockaddr *) &client_address, client_address_len);
    }

    pid_t pid1;
    int mypipe[2];

    /* Create the pipe. */
    if (pipe (mypipe)){
        fprintf (stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }

    /* Create the child process. */
    pid1 = fork ();
    if (pid1 == (pid_t) 0) {
        /* This is the child process.
         Close other end first. */
        sleep(STIMEOUT);

        ssize_t status = -2;

        close(mypipe[0]);
        write(mypipe[1],&status, sizeof(ssize_t));
        close(mypipe[1]);

        exit(EXIT_SUCCESS);
    } else if (pid1 < (pid_t) 0){
        /* The fork failed. */
        fprintf (stderr, "Fork failed.\n");
        return EXIT_FAILURE;
    } else {
        pid_t pid2;

        pid2 = fork();

        if (pid2 == (pid_t) 0) {

            ssize_t status;
            ssize_t in_len = recvfrom(fd, inbuff, block_size + header_size, 0, nullptr, nullptr);

            int resp_seq = Protocol::get_sequence(inbuff);
            string resp_msg = Protocol::get_message(inbuff, in_len);

            Debug::printl("\nrec: seg " + std::to_string(resp_seq)
                          + ", " + std::to_string(in_len) +  " bytes\n"
                          + "msg: " + resp_msg + "\n");

            // check to see if ACK sequence matches sequence sent
            // if so, increment sequence and send next block of data
            // else resend
            if (resp_msg.compare(0,3,"ACK") == 0){
                if(Protocol::get_sequence(inbuff) >= seq){
                    status = in_len;
                } else {
                    status = -1;
                }
            }

            close(mypipe[0]);
            write(mypipe[1], &status, sizeof(ssize_t));
            close(mypipe[1]);

            exit(EXIT_SUCCESS);
        } else if ( pid2 > (pid_t) 0 ){
            /* This is the parent process.
            Close other end first. */

            ssize_t recv_status = 0;

            close (mypipe[1]);
            read(mypipe[0], &recv_status, sizeof(ssize_t));
            close (mypipe[0]);

            if (recv_status == -2){
                kill(pid2, SIGKILL);
            } else {
                kill(pid1, SIGKILL);
            }

            return recv_status;
        }
    }

    return -3;
}

int Server::send_msg(int fd, std::string message, struct sockaddr_in client_address, socklen_t client_address_len) {

    // create out buffer
    char out_buff[message.length() + header_size];

    // create protocol message
    bzero(out_buff, sizeof(out_buff));
    Protocol::create_message(0, out_buff, message.c_str(), 0, message.length());

    // send error message to client
    int out_len = sendto(fd, out_buff, sizeof(out_buff), 0,
                         (struct sockaddr *)&client_address,
                         client_address_len);

    return out_len;
}

void Server::open_connection() {
    // create a UDP socket, creation returns -1 on failure
    if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
        Debug::printl("Error! Could not create server socket...");
        exit(EXIT_FAILURE);
    }
    Debug::printl("Server socket created.");

    // bind it to listen to the incoming connections on the created server
    // address, will return -1 on error
    if ((bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address))) < 0) {
        Debug::printl("Error! Could not bind server socket...");
        exit(EXIT_FAILURE);
    }
    Debug::printl("Binding socket successful.");
}

void Server::stop() {
    close(sockfd);
    Debug::printl("\n=====================\n Stopping Server \n=====================");
    Debug::printl("Server socket closed...");
    Debug::printl("Server stopped succesfully.");

    exit(EXIT_SUCCESS);
}

bool Server::recv_file(char *file_buffer, std::string file_path) {

    FILE *fp;
    fp = fopen(file_path.c_str(), "r");

    if (fp!=NULL) {
        char c = '\0';

        int index = 0;
        while (fscanf(fp, "%c", &c) != EOF) {
            file_buffer[index] = c;
            index++;
        }
        file_buffer[index] = '\0';
        fclose(fp);

        return true;
    }
    return false;
}

long Server::get_file_size(std::string filename) {
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

int Server::get_port() {
    return port;
}