//
// Created by Zachary Aries on 2018-02-25.
//

#ifndef ASSIGN_2_SERVER_H
#define ASSIGN_2_SERVER_H

#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <math.h>
#include <sys/stat.h>
#include <string>
#include <signal.h>

#include "Debug.h"
#include "FileHelper.h"
#include "Protocol.h"

#define FILE_ROOT "../files/"
#define STIMEOUT 2
#define MAXTIMEOUTS 10

class Server {
    size_t block_size;
    static const size_t header_size = 1;

    int port;
    bool run;
    struct sockaddr_in server_address;

    static int sockfd;

public:
    Server(int port, size_t block_size);

    void start();
    static void stop();

    void open_connection();
    int process_request(int fd, char *in_buffer, size_t in_buff_len, struct sockaddr_in client_address, socklen_t client_address_len);
    int send_msg(int fd, std::string message, struct sockaddr_in client_address, socklen_t client_address_len);
    ssize_t send_recv(int fd, unsigned short seq, int index, const char *msg, int msg_len, char * in_buff,
                      struct sockaddr_in client_address, socklen_t client_address_len);

    int get_port();
    long get_file_size(std::string filename);

    bool recv_file(char *buffer, std::string filepath);
};


#endif //ASSIGN_2_SERVER_H
