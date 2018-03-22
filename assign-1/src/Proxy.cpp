//
// Created by Zachary Aries on 2018-01-31.
//

#include "Proxy.h"

using std::cout;
using std::endl;
using std::string;

Proxy::Proxy(int port_server, int port_client, int byte_range_size)
    : server("Server 01", port_server),
      client("Client 01", port_client)
{
    this->port_server = port_server;
    this->port_client = port_client;
    this->byte_range_size = byte_range_size;

    cout << "\n--------\n Server \n--------\n";
    cout << "name: " << this->server.getName() << endl;
    cout << "port: " << this->server.getPort() << endl;

    cout << "\n--------\n Client \n--------\n";
    cout << "name: " << this->client.getName() << endl;
    cout << "port: " << this->client.getPort() << endl;
}

// Regular Proxy Function
void Proxy::start() {
    server.intitialize_server();

    stop = false; // bool to manually stop listen
    int i = 0;
    while (!stop){  // loop to keep listen socket open
        string client_msg = server.wait_for_message(); // open socket for browser and wait for request

        HttpHeader httpRequest(client_msg); // set up httpRequest object (should just be named HTTP object)
        client.intialize_client(httpRequest);
        string server_response = client.send_recv(client_msg, httpRequest); // send request to server to get data

        server.sendMessage(server_response); // send acquired data to browser

        client.closeSocket();
        server.closeDataSocket();
    }

    server.closeListenSocket();
}

// Sloxy Function
void Proxy::start_slow() {
    server.intitialize_server();

    stop = false; // bool to manually stop listen
    int i = 0;
    while (!stop){ // loop to keep listen socket open
        string client_msg = server.wait_for_message(); // open socket for browser and wait for request
        string header;
        string body;
        string server_response;

        // Content Length for Pages
        // 1 = 376
        // 2 = 1646
        // 3 = 8411

        for (i = 0; i < 1647; i++) {    // loop to get all data from server
            HttpHeader httpRequest(client_msg);
            httpRequest.addField(string("Range: bytes=") + std::to_string(i) + string("-") + std::to_string(i + (byte_range_size))); // add range field to header
            string httpResponse = httpRequest.getFormattedHeader(); // create modified header with range to send to server

            client.intialize_client(httpRequest);

            server_response = client.send_recv(httpResponse, httpRequest); // get data from server
            body = body + httpRequest.getBodyFromResponse(server_response); // append each range of data to a string body for later return

            i += byte_range_size;   // increment current index
        }
        client.closeSocket();

        HttpHeader httpRequest(client_msg); // get fake header to return to browser
        client.intialize_client(httpRequest);
        string tmp_server_response = client.send_recv(client_msg, httpRequest); // query server for regular response

        header = httpRequest.getHeaderFromResponse(tmp_server_response);    // get header of response

        string response = header + body;    // append body to header
        server.sendMessage(response);   // send response to browser

        server.closeDataSocket();
    }

    server.closeListenSocket();
}