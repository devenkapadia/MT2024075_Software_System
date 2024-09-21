/*
============================================================================
Name : ./13a.c
Author : Kapadia Deven
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
            will send the signal (using kill system call). Find out whether the first program is able to catch
            the signal or not.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    signal(SIGSTOP, handle_signal);  // Attempt to catch SIGSTOP (this won't work)

    printf("Waiting to catch SIGSTOP (but it won't work)...\n");
    while (1) {
        sleep(1);  // Keep the process running
    }

    return 0;
}
