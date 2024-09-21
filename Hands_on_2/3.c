/*
============================================================================
Name : ./3.c
Author : Kapadia Deven
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

int main() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("Current limits - Soft limit: %lu, Hard limit: %lu\n", limit.rlim_cur, limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }

    limit.rlim_cur = 1024;

    if (setrlimit(RLIMIT_NOFILE, &limit) == 0) {
        printf("New limits set - Soft limit: %lu\n", limit.rlim_cur);
    } else {
        perror("setrlimit");
        exit(EXIT_FAILURE);
    }

    return 0;
}
