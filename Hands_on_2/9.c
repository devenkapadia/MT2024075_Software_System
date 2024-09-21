/*
============================================================================
Name : ./9.c
Author : Kapadia Deven
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_ignore_handler(int sig) {
    printf("SIGINT ignored, press Ctrl+C again to terminate.\n");
}

int main() {
    signal(SIGINT, sigint_ignore_handler);
    printf("SIGINT is now being ignored. Press Ctrl+C.\n");
    
    sleep(5);

    printf("Resetting SIGINT to default action. Press Ctrl+C to terminate.\n");
    signal(SIGINT, SIG_DFL);

    while (1) {
        pause();  
    }

    return 0;
}
