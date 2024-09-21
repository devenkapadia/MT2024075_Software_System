/*
============================================================================
Name : ./33b.c
Author : Kapadia Deven
Description : Write a program to communicate between two machines using socket.
Date: 20th Sep, 2024.
============================================================================
*/

// server.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  
    address.sin_port = htons(8080);  

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    listen(server_fd, 3);
    printf("Waiting for a connection...\n");

    new_socket = accept(server_fd, NULL, NULL);

    read(new_socket, buffer, sizeof(buffer));
    printf("Message from client: %s\n", buffer);

    char *message = "Hello from server";
    send(new_socket, message, strlen(message), 0);

    close(new_socket);
    close(server_fd);

    return 0;
}
