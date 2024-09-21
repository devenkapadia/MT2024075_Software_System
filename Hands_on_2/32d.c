/*
============================================================================
Name : ./32d.c
Author : Kapadia Deven
Description : Write a program to implement semaphore to protect any critical section.
            d. remove the created semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("semfile", 65);

    int semid = semget(key, 1, 0666);

    semctl(semid, 0, IPC_RMID);
    printf("Semaphore removed.\n");

    return 0;
}
