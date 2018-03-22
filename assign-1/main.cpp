#include <iostream>
#include "Proxy.h"

using std::cout;
using std::endl;
using std::string;

/*void startServer(){
    Server server_01 ("Server 01", 8001);
    cout << "\n--------\n Server \n--------\n";
    cout << "name: " << server_01.getName() << endl;
    cout << "port: " << server_01.getPort() << endl;

    //server_01.start();
    //server_01.test_start();

    string client_reqst = server_01.wait_for_message();

    cout << "Client Request: ";
    cout << client_reqst;
    cout << "\n-- end msg --\n";

    Client client_01 ("Client 01", 8001);
    cout << "\n--------\n Client \n--------\n";
    cout << "name: " << client_01.getName() << endl;
    cout << "port: " << client_01.getPort() << endl;

    client_01.send_recv(client_reqst);


}

void startClient(){
    Client client_01 ("Client 01", 1234657);
    cout << "\n--------\n Client \n--------\n";
    cout << "name: " << client_01.getName() << endl;
    cout << "port: " << client_01.getPort() << endl;

    client_01.start();
}*/

int main() {

    // Proxy init, browser-proxy port, proxy-server port, rate of bits per request
    Proxy proxy(8001,80,32);

    // uncomment proxy.start_slow() to test the sloxy functions
    // sizes of content have to be manually entered on line 67
    // of proxy class.

    proxy.start_slow();

    // proxy.start();

    return 0;
}

