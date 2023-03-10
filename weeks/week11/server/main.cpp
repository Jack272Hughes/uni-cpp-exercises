#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SOCKET_ERROR -1

using namespace std;

void printErrorWithMessageAndExit(string message) {
    cout << message << " with error: " << strerror(errno) << endl;
    exit(1);
}

int main() {
    // Create socket
    cout << "-=== Server Step 1 & 2 ===-" << endl;
    // WSAStartup is not needed for Mac
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == SOCKET_ERROR)
        printErrorWithMessageAndExit("Error creating socket");
    cout << "Socket create successfully!" << endl;

    // Bind socket
    cout << "-=== Server Step 3 ===-" << endl;
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    // If you wanted to accept from any IP use
    // address.sin_addr.s_addr = INADDR_ANY;

    if (::bind(serverSocket, (sockaddr*) &address, sizeof(address)) == SOCKET_ERROR)
        printErrorWithMessageAndExit("Error trying to bind the socket");
    cout << "Socket successfully bound!" << endl;

    // Listen on socket
    cout << "-=== Server Step 4 ===-" << endl;
    if(listen(serverSocket, 1) == SOCKET_ERROR)
        printErrorWithMessageAndExit("Error trying to listen on bound socket");
    cout << "Listening on bound socket!" << endl;

    // Accept connection on socket
    cout << "-=== Server Step 5 ===-" << endl;
    sockaddr_storage connectedClient;
    socklen_t connectedClientSize = sizeof(connectedClient);

    int acceptedSocket = accept(serverSocket, (sockaddr*) &connectedClient, &connectedClientSize);

    if (acceptedSocket == SOCKET_ERROR)
        printErrorWithMessageAndExit("Error while accepting socket");
    cout << "Accepted a socket!" << endl;
    
    cout << "-=== Server Additional Details ===-" << endl;
    // Get info of the incoming connection
    char hostName[NI_MAXHOST], serviceName[NI_MAXSERV];
    if (getnameinfo((sockaddr*) &connectedClient, connectedClientSize, hostName, NI_MAXHOST, serviceName, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV) == SOCKET_ERROR)
        printErrorWithMessageAndExit("Error while trying to get information about connection");
    cout << "Connection was from host: '" << hostName << "' and port '" << serviceName << "'" << endl;

    shutdown(serverSocket, SHUT_RDWR);
}
