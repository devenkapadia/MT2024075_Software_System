/*
============================================================================
Name : ./34b.c
Author : Kapadia Deven
Description : Write a program to create a concurrent server.
            b. use pthread_create
Date: 20th Sep, 2024.
============================================================================
*/

// server_thread.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

void *handle_client(void *socket_desc) {
    int new_socket = *(int *)socket_desc;
    char buffer[1024] = {0};
    read(new_socket, buffer, sizeof(buffer));
    printf("Message from client: %s\n", buffer);
    char *message = "Hello from server";
    send(new_socket, message, strlen(message), 0);
    close(new_socket);
    free(socket_desc);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket;
        pthread_t client_thread;
        pthread_create(&client_thread, NULL, handle_client, (void *)new_sock);
        pthread_detach(client_thread);
    }

    close(server_fd);
    return 0;
}
