#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

void printErrorWithMessageAndExit(string message) {
    cout << message << " with error: " << strerror(errno) << endl;
    exit(1);
}

int main() {
    // Create socket
    cout << "-=== Client Step 1 & 2 ===-" << endl;
    // WSAStartup is not needed for Mac
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == -1)
        printErrorWithMessageAndExit("Error creating socket");
    cout << "Socket create successfully!" << endl;

    // Connect socket to server
    cout << "-=== Client Step 3 ===-" << endl;
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(clientSocket, (sockaddr*) &address, sizeof(address)) == -1)
        printErrorWithMessageAndExit("Error while connecting to server socket");
    cout << "Successfully connected to server socket!" << endl;
}
