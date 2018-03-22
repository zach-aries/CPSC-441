//
// Created by Zachary Aries on 2018-01-31.
//

#ifndef ASSIGN_1_PROXY_H
#define ASSIGN_1_PROXY_H

#include <iostream>
#include <string>

#import "Server.h"
#import "Client.h"
#import "HttpHeader.h"


class Proxy {
    int port_server;
    int port_client;
    int byte_range_size;

    bool stop;

    Server server;
    Client client;

public:
    Proxy(int port_server, int port_client, int byte_range_size);

    void start();
    void start_slow();
};


#endif //ASSIGN_1_PROXY_H
