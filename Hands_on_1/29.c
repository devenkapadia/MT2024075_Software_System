/*

Name: 29.c
Author: Kapadia Deven
Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
            SCHED_RR).
Date: 30 Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy = sched_getscheduler(0);
    if (policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    switch (policy) {
        case SCHED_OTHER:
            printf("Current Policy: SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Current Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current Policy: SCHED_RR\n");
            break;
        default:
            printf("Unknown Policy\n");
            break;
    }

    struct sched_param param;
    param.sched_priority = 1;  
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }
    printf("Scheduling policy changed to SCHED_FIFO\n");

    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }
    printf("Scheduling policy changed to SCHED_RR\n");

    return 0;
}


/*

sudo ./p29
[sudo] password for deven: 
Current Policy: SCHED_OTHER
Scheduling policy changed to SCHED_FIFO
Scheduling policy changed to SCHED_RR

*/