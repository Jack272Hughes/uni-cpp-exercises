#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

#define SOCKET_ERROR -1

using namespace std;

void printErrorWithMessageAndExit(string message) {
    cout << message << " with error: " << strerror(errno) << endl;
    exit(1);
}

class Data {
public:
    int health;
    char name[50];
};

int main() {
    // Create socket
    cout << "-=== Week 11 ===-" << endl;
    cout << "-=== Client Step 1 & 2 ===-" << endl;
    // WSAStartup is not needed for Mac
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == SOCKET_ERROR)
        printErrorWithMessageAndExit("Error creating socket");
    cout << "Socket created successfully!" << endl;

    // Connect socket to server
    cout << "-=== Client Step 3 ===-" << endl;
    sockaddr_in address = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr = { .s_addr = inet_addr("127.0.0.1") }
    };

    if(connect(clientSocket, (sockaddr*) &address, sizeof(address)) == SOCKET_ERROR)
        printErrorWithMessageAndExit("Error while connecting to server socket");
    cout << "Successfully connected to server socket!" << endl;

    cout << "-=== Week 12 ===-" << endl;
    cout << "-=== Exercise 1 & 2 & 3 ===-" << endl;
    char buffer[200];
    bool shouldContinue = true;
    while (shouldContinue) {
        printf("What message do you want to send to the server?\n");
        cin.getline(buffer, 200);

        send(clientSocket, &buffer, sizeof(buffer), 0);
        
        int byteCount = recv(clientSocket, buffer, sizeof(buffer), 0);
        switch(byteCount) {
            case -1:
                printErrorWithMessageAndExit("Error while waiting for a message to be received");
                break;
            case 0:
                cout << "The connection was closed by the client" << endl;
                break;
            default:
                if (strcmp(buffer, "SHUTDOWN") == 0) shouldContinue = false;
                else cout << "Received message: " << buffer << endl;
        }
    }

    cout << "Shutting down..." << endl;

    shutdown(clientSocket, SHUT_RDWR);
}
