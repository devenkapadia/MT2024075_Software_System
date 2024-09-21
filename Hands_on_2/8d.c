/*
============================================================================
Name : ./8d.c
Author : Kapadia Deven
Description : Write a separate program using signal system call to catch the following signals.
            d. SIGALRM (use alarm system call)
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int sig) {
    printf("Caught SIGALRM: Timer expired\n");
}

int main() {
    signal(SIGALRM, sigalrm_handler);

    alarm(5);

    while (1);

    return 0;
}
