/*
============================================================================
Name : ./8c.c
Author : Kapadia Deven
Description : Write a separate program using signal system call to catch the following signals.
            c. SIGFPE
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int sig) {
    printf("Caught SIGFPE: Divide by zero\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);
    // Exceptions include overflows, under-flows, and division by zero.

    int x = 5 / 0;

    return 0;
}
