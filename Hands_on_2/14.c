/*
============================================================================
Name : ./14.c
Author : Kapadia Deven
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
            the monitor.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipefd[2];  
    const char *message = "hey how are you?";
    size_t message_len = strlen(message) + 1;
    
    // Creating a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Writing to the pipe
    write(pipefd[1], message, message_len);
    close(pipefd[1]);

    // Reading from the pipe
    char buffer[100];
    ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';
    printf("Read from pipe: %s\n", buffer);

    close(pipefd[0]);

    return 0;
}
