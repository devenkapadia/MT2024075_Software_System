/*
============================================================================
Name : ./23.c
Author : Kapadia Deven
Description : Write a program to print the maximum number of files can be opened within a process and
            size of a pipe (circular buffer).
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {

    long max_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", max_files);

    return 0;
}
