//
// Created by Zachary Aries on 2018-01-31.
//

#include "Client.h"

using std::string;
using std::cout;
using std::endl;

Client::Client(std::string name, int port) {
    this -> port = port;
    this -> name = std::move(name);
    this -> backlog_queue_size = 10;
}

void Client::intialize_client() {
    cout << "\n---------------------\n Initializing Client \n---------------------\n";

    // Initialize address
    addr_proxy.sin_family = AF_INET;
    addr_proxy.sin_port = htons(this->port);
    addr_proxy.sin_addr.s_addr = htonl(INADDR_ANY);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0 ) {
        cout << "Error! Problem in socket() call...";
        exit(-1);
    } else {
        cout << "Creating Socket File Descriptor: done.\n";
    }

    cout << "\nInitializing Client: done.\n";
}

void Client::intialize_client(HttpHeader header) {
    cout << "\n---------------------\n Initializing Client \n---------------------\n";


    /* Creating the TCP socket for connecting to the desired web server */
    // Address initialization
    struct hostent *server;
    server = gethostbyname(header.host);

    if (server == nullptr) {
        cout << "Error! Could not resolve hostname...\n";
    } else {
        cout << "Web Server: " << server->h_name << endl;
    }

    // Initialize socket structure
    bzero((char *) &addr_proxy, sizeof(addr_proxy));
    addr_proxy.sin_family = AF_INET;
    addr_proxy.sin_port = htons(this->port);
    bcopy((char *) server->h_addr, &addr_proxy.sin_addr.s_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0 ) {
        cout << "Error! Problem in socket() call...";
        exit(-1);
    } else {
        cout << "Creating Socket File Descriptor: done.\n";
    }

    cout << "Initializing Proxy Client: done.\n";
}

string Client::send_recv(std::string send_message, HttpHeader header) {
    char *s_message_out = &send_message[0u];
    char c_message_in[1024];

    // Connecting to the web server's socket
    int cnect_status;
    cnect_status = connect(sockfd, (struct sockaddr *) &addr_proxy,
                           sizeof(struct sockaddr_in));

    if (cnect_status < 0 ) {
        cout << "Error! Problem in connect()...\n";
        exit(-1);
    } else {
        cout << "\n------------------\n Client Connected \n------------------\n";
    }

    cout << "message sent: " << s_message_out << endl;

    int web_send_status;
    web_send_status = send(sockfd, s_message_out, sizeof(c_message_in), 0);
    if (web_send_status < 0) {
        cout << "Error! Problem with send() call in HTTP request to the web server\n";
        exit(-1);
    }else{
        cout << "Sending HTTP Request To Server: done.\n";
        cout << "Message:\n" << s_message_out << endl;
    }

    /* Receiving the HTTP response from the web server */
    cout << "Waiting for HTTP response from web server...\n";
    char w_message_in[10000];
    int web_recv_status;
    web_recv_status = recv(sockfd, w_message_in, sizeof(w_message_in), 0);
    if (web_recv_status < 0) {
        cout << "Error! Problem in recv() call for receiving web server's HTTP response.\n";
        exit(-1);
    } else {
        cout << "Receiving HTTP Response: done.\n";
    }

    return string(w_message_in);
}

void Client::closeSocket() {
    close(sockfd);
}

int Client::getPort() {
    return port;
}

string Client::getName() {
    return name;
}