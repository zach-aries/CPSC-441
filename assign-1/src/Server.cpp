//
// Created by Zachary Aries on 2018-01-31.
//

#include "Server.h"

using std::string;
using std::cout;
using std::endl;

Server::Server(string name, int port) {
    this -> port = port;
    this -> name = std::move(name);
    this -> backlog_queue_size = 10;    // default backlog queue size
}

void Server::intitialize_server() {
    cout << "\n---------------------\n Initializing Server \n---------------------\n";

    // Initialize address
    addr_proxy.sin_family = AF_INET;
    addr_proxy.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_proxy.sin_port = htons(this->port);
    cout << "Address Initialization: done.\n";

    // Create the listening socket for server
    lstn_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (lstn_sock < 0) {
        cout << "Error! Problem in socket() call...\n";
        exit(-1);
    } else {
        cout << "Creating Socket File Descriptor: done.\n";
    }

    // Bind the socket to the address and port
    int bind_status;
    bind_status = bind(lstn_sock, (struct sockaddr *) &addr_proxy,
                       sizeof(struct sockaddr_in));

    if (bind_status < 0) {
        cout << "Error! Problem in binding() call...\n";
        exit(-1);
    } else {
        cout << "Socket Binding: done.\n";
    }

    int lstn_status;
    lstn_status = listen(lstn_sock, backlog_queue_size);
    if (lstn_status < 0) {
        cout << "Error! Problem in listen() call...\n";
    } else {
        cout << "Socket Listening: done.\n";
    }


    cout << "\nInitializing Server: done.\n";
}

string Server::wait_for_message() {
    cout << "\n----------------\n Server Started \n----------------\n";
    cout << "Waiting For Connection...\n";
    // Accept a connection
    data_sock = accept(lstn_sock, nullptr, nullptr);
    if (data_sock < 0) {
        cout << "Error! Problem with accept() call";
        exit(-1);
    } else {
        cout << "Accepting Connection Request: done.\n";
    }

    // Receive data
    int recv_status;
    char rcv_message[1024];

    recv_status = recv(data_sock, rcv_message, sizeof(rcv_message), 0);

    if (recv_status < 0) {
        cout << "Error! Problem with recv()\n";
    } else {
        cout << "Message Received: \n\n" << rcv_message;
    }

    return string(rcv_message);
}

void Server::sendMessage(string message) {
    char s_message_out[message.size()+1]; //as 1 char space for null is also required
    strcpy(s_message_out, message.c_str());

    // Sending the HTTP response to the client
    int c_send_status;
    c_send_status = send(data_sock, s_message_out, sizeof(s_message_out), 0);
    if (c_send_status < 0) {
        cout << "Error! Problem with send() call in HTTP response to client.\n";
        exit(-1);
    } else {
        cout << "HTTP Response to Client: done.\n";
    }
}

void Server::closeListenSocket() {
    close(lstn_sock);
}

void Server::closeDataSocket() {
    close(data_sock);
}

int Server::getPort() {
    return port;
}

string Server::getName() {
    return name;
}

