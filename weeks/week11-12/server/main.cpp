#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

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

string returnMessage = "Message Received";
void* handleConnection(void* input) {
    int* socket = (int*) input;
    char buffer[200];
    
    int byteCount;
    do {
        byteCount = recv(*socket, buffer, sizeof(buffer), 0);

        switch(byteCount) {
            case -1:
                printErrorWithMessageAndExit("Error while waiting for a message to be received");
                break;
            case 0:
                cout << "The connection was closed by the client" << endl;
                break;
            default:
                cout << "Received message: " << buffer << endl;
        }

        send(*socket, &returnMessage, sizeof(returnMessage), 0);
    } while (byteCount != 0);
    return 0;
}

int main() {
    // Create socket
    cout << "-=== Week 11 ===-" << endl;
    cout << "-=== Server Step 1 & 2 ===-" << endl;
    // WSAStartup is not needed for Mac
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket == SOCKET_ERROR)
        printErrorWithMessageAndExit("Error creating socket");
    cout << "Socket created successfully!" << endl;

    // Bind socket
    cout << "-=== Server Step 3 ===-" << endl;
    sockaddr_in address = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr = { .s_addr = inet_addr("127.0.0.1") }
    };
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
    // sockaddr_storage connectedClient;
    // socklen_t connectedClientSize = sizeof(connectedClient);

    // int acceptedSocket = accept(serverSocket, (sockaddr*) &connectedClient, &connectedClientSize);

    // if (acceptedSocket == SOCKET_ERROR)
    //     printErrorWithMessageAndExit("Error while accepting socket");
    // cout << "Accepted a socket!" << endl;
    
    // cout << "-=== Server Additional Details ===-" << endl;
    // // Get info of the incoming connection
    // char hostName[NI_MAXHOST], serviceName[NI_MAXSERV];
    // if (getnameinfo((sockaddr*) &connectedClient, connectedClientSize, hostName, NI_MAXHOST, serviceName, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV) == SOCKET_ERROR)
    //     printErrorWithMessageAndExit("Error while trying to get information about connection");
    // cout << "Connection was from host: '" << hostName << "' and port '" << serviceName << "'" << endl;

    cout << "-=== Week 12 ===-" << endl;
    // cout << "-=== Exercise 1 & 2 & 3 & 4 ===-" << endl;
    // string returnMessage = "Message Received";
    // char buffer[200];
    
    // int byteCount;
    // do {
    //     byteCount = recv(acceptedSocket, buffer, sizeof(buffer), 0);

    //     switch(byteCount) {
    //         case -1:
    //             printErrorWithMessageAndExit("Error while waiting for a message to be received");
    //             break;
    //         case 0:
    //             cout << "The connection was closed by the client" << endl;
    //             break;
    //         default:
    //             cout << "Received message: " << buffer << endl;
    //     }

    //     send(acceptedSocket, &returnMessage, sizeof(returnMessage), 0);
    // } while (byteCount != 0);

    cout << "-=== Exercise 5 ===-" << endl;
    while (true) {
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

        pthread_t thread;
        int errorNum = pthread_create(&thread, NULL, handleConnection, &acceptedSocket);
        if (errorNum != 0) {
            cout << "Error while creating thread to handle connection: " << strerror(errorNum) << endl;
            shutdown(acceptedSocket, SHUT_RDWR);
        }
    }
    
    shutdown(serverSocket, SHUT_RDWR);
}
