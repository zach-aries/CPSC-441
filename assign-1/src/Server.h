//
// Created by Zachary Aries on 2018-01-31.
//

#ifndef ASSIGN_1_SERVER_H
#define ASSIGN_1_SERVER_H

#include <iostream>

#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

class Server {
    std::string name;
    int port;
    int backlog_queue_size; // default value = 10

    int data_sock;
    int lstn_sock;

    struct sockaddr_in addr_proxy;

public:
    // init with default backlog_queue_size
    Server(std::string name, int port);
    // TODO create constructor with set backlog queue size
    //Server(std::string name, int port, backlog_queue_size);

    void intitialize_server();

    std::string wait_for_message();
    void sendMessage(std::string);
    void closeListenSocket();
    void closeDataSocket();

    int getPort();
    std::string getName();
};


#endif //ASSIGN_1_SERVER_H
