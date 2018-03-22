//
// Created by Zachary Aries on 2018-02-28.
//

#include "Protocol.h"

using std::string;

int Protocol::calc_block_size(int remaining_file_size) {
    int block = 8888;
    int partial_block;

    if (remaining_file_size >= 8888){
        return  block / 8;
    } else if (remaining_file_size > 8) {
        partial_block = remaining_file_size - (remaining_file_size % 8);
        return  partial_block / 8;
    } else {
        return 1;
    }
}

void Protocol::create_message(unsigned short seq, char *buffer, const char *message, int index, int nbytes) {

    unsigned char seq_bytes[1];
    seq_bytes[0] = seq & 0xFF;

    memcpy(buffer, seq_bytes, 1);
    memcpy(buffer + 1, message + index, (size_t)nbytes);
}

string Protocol::get_message(char *data_buffer, ssize_t msg_len) {
    char msg_cstr[msg_len];
    strncpy(msg_cstr, data_buffer + 1, msg_len);

    msg_cstr[msg_len - 1] = '\0';

    return string(msg_cstr);
}

int Protocol::get_sequence(char *data_buffer) {
    unsigned short seq;

    seq = data_buffer[0] & 0xFF;

    return seq;
}