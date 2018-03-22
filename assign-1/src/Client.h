//
// Created by Zachary Aries on 2018-01-31.
//

#ifndef ASSIGN_1_CLIENT_H
#define ASSIGN_1_CLIENT_H

/* Standard libraries */
#include <iostream>
#include <string>

/* Libraries for socket programming */
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

/* Libraries for web programming */
#include <netdb.h>

/* Custom Classes */
#include "HttpHeader.h"

class Client {
    std::string name;
    int port;
    int sockfd;
    int backlog_queue_size; // default value = 10

    bool stop;

    struct sockaddr_in addr_proxy;


public:
    Client(std::string name, int port);

    std::string send_recv(std::string, HttpHeader);

    void intialize_client();
    void intialize_client(HttpHeader);
    void closeSocket();

    int getPort();
    std::string getName();
};


#endif //ASSIGN_1_CLIENT_H
