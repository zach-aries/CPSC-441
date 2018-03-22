//
// Created by Zachary Aries on 2018-02-01.
//

#ifndef ASSIGN_1_HTTP_PARSER_H
#define ASSIGN_1_HTTP_PARSER_H

/* Standard Libraries */
#include <string>
#include <vector>

/* Libraries for web programming */
#include <netdb.h>

class HttpHeader {
    std::string header;
    std::vector<std::string> tokenArray;
    std::string body;

public:
    char request[1024];
    char url[1024];
    char host[1024];
    char path[1024];

    explicit HttpHeader(std::string);

    void addField(std::string);
    void changeRequest(std::string);

    std::string getHttpHeader();
    std::string getFormattedHeader();
    std::string getBodyFromResponse(std::string);
    std::string getHeaderFromResponse(std::string);

    int getContentLengthFromHeader();
};


#endif //ASSIGN_1_HTTP_PARSER_H
