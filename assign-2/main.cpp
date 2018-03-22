#include <iostream>

#include "Debug.h"
#include "Server.h"
#include "Client.h"

#define BLOCK_SIZE 1111

using std::string;

/* The function will run after catching Ctrl+c in terminal */
void catcher(int sig) {
    Server::stop();
    Debug::printl("\nCatcher with signal: " + std::to_string(sig));
}

int main(int argc, char *argv[]) {

    string type = argv[1];

    if(type == "-s"){
        if(argc > 3){
            string debug = argv[3];

            // turn debug off or on
            if(debug == "true"){
                Debug::setDebug(true);
            }
        }

        int port = std::stoi(argv[2]);
        /* For catching Crtl+c in terminal */
        signal(SIGINT, catcher);

        Server s(port, BLOCK_SIZE);
        s.start();
    }else if(type == "-c"){
        string server = argv[2];
        int port = std::stoi(argv[3]);

        if(argc > 4){
            string debug = argv[4];

            // turn debug off or on
            if(debug == "true"){
                Debug::setDebug(true);
            }
        }

        bool run = true;
        while (run) {
            string input;
            std::cout << "\nPlease enter a file name (-q to quit): ";
            std::cin >> input;

            if (input != "-q"){
                Client c(port, server, BLOCK_SIZE);
                c.get_file(input);
            } else {
                run = false;
            }
        }
    }


    return 0;
}