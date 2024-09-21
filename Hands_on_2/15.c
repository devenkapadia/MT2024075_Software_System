/*
============================================================================
Name : ./15.c
Author : Kapadia Deven
Description : Write a simple program to send some data from parent to the child process.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipefd[2]; 
    int pid;
    const char *message = "Hello from parent!";
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipefd[1]); 

        ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1);
        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[bytes_read] = '\0';
        printf("Child received: %s\n", buffer);

        close(pipefd[0]);  
    } else {
        close(pipefd[0]);  
        printf("Hello, I am Parent\n");

        write(pipefd[1], message, strlen(message) + 1);  

        close(pipefd[1]);  
    }

    return 0;
}
