/*
============================================================================
Name : ./5.c
Author : Kapadia Deven
Description : Write a program to print the system limitation of
            a. maximum length of the arguments to the exec family of functions.
            b. maximum number of simultaneous process per user id.
            c. number of clock ticks (jiffy) per second.
            d. maximum number of open files
            e. size of a page
            f. total number of pages in the physical memory
            g. number of currently available pages in the physical memory.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/sysinfo.h>  // For getting total and available pages

int main() {
    // a. Maximum length of the arguments to the exec family of functions
    long arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of the arguments to the exec family of functions: %ld\n", arg_max);

    // b. Maximum number of simultaneous processes per user id
    long max_processes = sysconf(_SC_CHILD_MAX);
    printf("Maximum number of simultaneous processes per user id: %ld\n", max_processes);

    // c. Number of clock ticks (jiffy) per second
    long clock_ticks = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks (jiffy) per second: %ld\n", clock_ticks);

    // d. Maximum number of open files
    long open_max = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", open_max);

    // e. Size of a page
    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    // f. Total number of pages in the physical memory
    long total_pages = sysconf(_SC_PHYS_PAGES);
    printf("Total number of pages in the physical memory: %ld\n", total_pages);

    // g. Number of currently available pages in the physical memory
    long avail_pages = sysconf(_SC_AVPHYS_PAGES);
    printf("Number of currently available pages in the physical memory: %ld\n", avail_pages);

    return 0;
}
