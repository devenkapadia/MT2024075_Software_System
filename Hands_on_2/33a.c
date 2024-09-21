/*
============================================================================
Name : ./33a.c
Author : Kapadia Deven
Description : Write a program to communicate between two machines using socket.
Date: 20th Sep, 2024.
============================================================================
*/

// client.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);  

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    char *message = "Hello from client";
    send(sock, message, strlen(message), 0);

    read(sock, buffer, sizeof(buffer));
    printf("Message from server: %s\n", buffer);

    close(sock);

    return 0;
}
