#include <iostream>
#include <winsock2.h>
using namespace std;

#define PORT 8080 

struct sockaddr_in srv;

int main(){

    int nRet = 0;
    // Initialize the WSA variables 
    WSADATA* ws = new WSADATA;
    if ( WSAStartup(MAKEWORD(2,2), ws) < 0){
        cout << endl << "WSA failed to intialize";
    }else{
        cout << endl << "WSA intialized";
    }

   // initialize the socket
    int nSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(nSocket < 0){
        cout << endl << "The socket did not open";
    }else{
        cout << endl << "The socket opened successfully";
    }

    // intialized the environment for sockaddr structure
    srv.sin_family = AF_INET;
    srv.sin_port = htons(PORT);
    srv.sin_addr.s_addr = INADDR_ANY;
    memset(&(srv.sin_zero), 0, 8);

   // Bind the socket the local port

    nRet = bind(nSocket, (sockaddr*)&srv, sizeof(sockaddr));
    if (nRet < 0){
        cout << endl << "Bind failed";
        exit(EXIT_FAILURE);
    }else{
        cout << endl << "Successfully bind to local port";
    }

   // Listen the request from client 
    nRet = listen(nSocket, 5);
    if (nRet < 0){
        cout << endl << "Listening failed";
        exit(EXIT_FAILURE);
    }else{
        cout << endl << "Started listening to local port";
    }

   // Keep waiting for new requests and proceed as per the request
}