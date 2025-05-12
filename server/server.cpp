
#include <winsock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA WSAData;
    SOCKET server, client;
    SOCKADDR_IN serverAddr, clientAddr;

    WSAStartup(MAKEWORD(2, 0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(5555);

    bind(server, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    listen(server, 0);

    std::cout << "Listening for incoming connections..." << std::endl;

    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);
    if ((client = accept(server, (SOCKADDR *)&clientAddr, &clientAddrSize))) {
        std::cout << "Client connected!" << std::endl;

        recv(client, buffer, sizeof(buffer), 0);
        std::cout << "Client says: " << buffer << std::endl;
        closesocket(client);
        std::cout << "Client disconnected." << std::endl;
    }

    WSACleanup();
    return 0;
}
