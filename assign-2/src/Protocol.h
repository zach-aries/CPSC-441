//
// Created by Zachary Aries on 2018-02-28.
//

#ifndef ASSIGN_2_PROTOCOL_H
#define ASSIGN_2_PROTOCOL_H

#include <netinet/in.h>
#include <string>

#include "Debug.h"

class Protocol {

public:
    static int calc_block_size(int remaining_file_size);

    static void create_message(unsigned short seq, char *buffer, const char *msg,int index, int nbytes);
    static std::string get_message(char *data_buffer, ssize_t msg_len);
    static int get_sequence(char *data_buffer);
};


#endif //ASSIGN_2_PROTOCOL_H
