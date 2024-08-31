/*

Name: 28.c
Author: Kapadia Deven
Description: Write a program to get maximum and minimum real time priority.
Date: 30 Aug, 2024

*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max_priority_fifo, min_priority_fifo;
    int max_priority_rr, min_priority_rr;

    max_priority_fifo = sched_get_priority_max(SCHED_FIFO);
    min_priority_fifo = sched_get_priority_min(SCHED_FIFO);

    max_priority_rr = sched_get_priority_max(SCHED_RR);
    min_priority_rr = sched_get_priority_min(SCHED_RR);

    printf("SCHED_FIFO: Max priority = %d, Min priority = %d\n", max_priority_fifo, min_priority_fifo);
    printf("SCHED_RR: Max priority = %d, Min priority = %d\n", max_priority_rr, min_priority_rr);

    return 0;
}


/*

SCHED_FIFO: Max priority = 99, Min priority = 1
SCHED_RR: Max priority = 99, Min priority = 1

*/