/*
============================================================================
Name : ./8a.c
Author : Kapadia Deven
Description : Write a separate program using signal system call to catch the following signals.
            a. SIGSEGV
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int sig) {
    signal(sig, sigsegv_handler);
    printf("Caught SIGSEGV: Segmentation fault\n Singal Number is %d\n", sig); 
    exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    int *ptr = NULL;
    *ptr = 42;
    // ptr points to  NULL location and it is trying to write 42 in the NULL location  
    // this will lead to segmentation fault

    return 0;
}
