//
// Created by Zachary Aries on 2018-02-25.
//

#ifndef ASSIGN_2_CLIENT_H
#define ASSIGN_2_CLIENT_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <signal.h>
#include <fstream>

#include "Debug.h"
#include "Protocol.h"

#define TIMEOUT 2
#define MAXTIMEOUT 10
#define OUTPUT_ROOT "../output/"

class Client {
    size_t block_size;
    const size_t header_size = 1;

    int server_port;
    int sockfd;

    std::string server_name;
    struct sockaddr_in server_address;
    socklen_t server_address_len;

public:
    Client(int server_port, std::string server_name, size_t block_size);

    ssize_t process_file(int fd, std::string file_request, std::string file_name);
    ssize_t send_msg(int fd, std::string message, struct sockaddr_in client_address, socklen_t client_address_len);

    void get_file(std::string message);
    void open_connection();
};


#endif //ASSIGN_2_CLIENT_H
