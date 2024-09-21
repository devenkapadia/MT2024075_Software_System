/*
============================================================================
Name : ./16.c
Author : Kapadia Deven
Description : Write a program to send and receive data from parent to child vice versa. Use two way
            communication.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipe1[2];  // Pipe for parent-to-child communication
    int pipe2[2];  // Pipe for child-to-parent communication
    int pid;
    const char *parent_message = "Hello from parent!";
    const char *child_message = "Hello from child!";
    char buffer[100];

    // Create the pipes
    if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a new process
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipe1[1]);  
        close(pipe2[0]); 

        // Read data from the parent
        ssize_t bytes_read = read(pipe1[0], buffer, sizeof(buffer) - 1);
        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_read] = '\0';
        printf("Child received: %s\n", buffer);

        // Send data to the parent
        write(pipe2[1], child_message, strlen(child_message) + 1);

        close(pipe1[0]); 
        close(pipe2[1]); 
    } else {
        // Parent process
        close(pipe1[0]); 
        close(pipe2[1]); 

        // Send data to the child
        write(pipe1[1], parent_message, strlen(parent_message) + 1);

        // Read data from the child
        ssize_t bytes_read = read(pipe2[0], buffer, sizeof(buffer) - 1);
        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        buffer[bytes_read] = '\0';
        printf("Parent received: %s\n", buffer);

        close(pipe1[1]); 
        close(pipe2[0]); 
    }

    return 0;
}
