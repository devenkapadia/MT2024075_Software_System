/*
============================================================================
Name : ./12.c
Author : Kapadia Deven
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
                the parent process from the child process.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        sleep(1); 
        printf("Child sending SIGKILL to parent (PID: %d)\n", getppid());
        kill(getppid(), SIGKILL);
        while (1) {
            sleep(5); 
        }
    } else if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) exiting\n", getpid());
        exit(0);
    } else {
        perror("fork");
        exit(1);
    }
}
