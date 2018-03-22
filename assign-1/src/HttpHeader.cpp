//
// Created by Zachary Aries on 2018-02-01.
//

#include <iostream>
#include "HttpHeader.h"

using std::string;
using std::cout;
using std::endl;

HttpHeader::HttpHeader(std::string header) {

    // getHeaderFields(header);

    cout << "\n----------------------\n Parsing HTTP Request \n----------------------\n";

    this->header = header;

    char *cstr = &header[0u];
    const char delimeter[3] = "\r\n";
    char *token;

    /* get the first token */
    token = strtok(cstr, delimeter);
    strcpy(request,token);

    int count = 0;
    for (int i = 0; i < header.size(); i++)
        if (header[i] == '\n') count++;


    /* walk through other tokens */
    while( token != NULL ) {
        token = strtok(NULL, delimeter);
        if(token != NULL){
            tokenArray.push_back(token);
            // printf( "Token: %s\n", token );
        }
    }

    /* Parsing the HTTP message to extract the HOST name of the desired web server */
    int i;
    // find and parse the GET request, isolating the url for later use
    char *pathname = strtok(cstr, "\r\n");

    cout << "\nHTTP Request: " << pathname << endl;
    if (sscanf(pathname, "GET http://%s", url) == 1) {
        cout << "URL: " << url << endl;
    }

    // seperate the hostname from the pathname
    for (i = 0; i < strlen(url); i++) {
        if (url[i] == '/') {
            strncpy(host, url, i); //copy out the hostname
            host[i] = '\0';
            break;
        }
    }

    bzero(path, 500); //to clear junk at the beginning of this buffer. don't know why its there
    for (; i < strlen(url); i++) {
        strcat(path, &url[i]); //copy out the path
        break;
    }

    cout << "Host: " << host << endl;
    cout << "Path: " << path << endl;
}

string HttpHeader::getHttpHeader() {
    return this->header;
}

string HttpHeader::getFormattedHeader(){
    string header = string(request) + "\r\n";

    for(int i = 0; i < tokenArray.size(); i++){
        header = header + tokenArray.at(i) + "\r\n";
    }

    header = header + "\r\n";

    return header;
}


void HttpHeader::addField(std::string field) {
    tokenArray.push_back(field);
}

string HttpHeader::getBodyFromResponse(std::string response) {
    const char delimeter[5] = "\r\n\r\n";
    int body_start_index = response.find(delimeter) + 4;
    string body = response.substr(body_start_index, response.length());

    return body;
}

string HttpHeader::getHeaderFromResponse(string response) {
    char *cstr = &response[0u];
    const char delimeter[5] = "\r\n\r\n";
    char *token;

    /* get the first token */
    token = strtok(cstr, delimeter);

    return  token;
}

void HttpHeader::changeRequest(std::string new_request) {

}

int HttpHeader::getContentLengthFromHeader() {
    char *cstr = &header[0u];
    const char delimeter1[17] = "Content-Length: ";
    const char delimeter2[5] = "\r\n";

    int c_length_start = header.find(delimeter1) + 16;
    int c_length_end = header.find(delimeter2);

    string contentLength = header.substr(c_length_start, c_length_end);

    int value = atoi(contentLength.c_str()); //value = 45

    return value;
}

