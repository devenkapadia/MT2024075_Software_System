/*
============================================================================
Name : ./31a.c
Author : Kapadia Deven
Description : Write a program to create a semaphore and initialize value to the semaphore.
            b. create a counting semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("semfile", 65);

    int semid = semget(key, 1, 0666 | IPC_CREAT);

    semctl(semid, 0, SETVAL, 1);

    printf("Binary semaphore created and initialized to 1.\n");

    return 0;
}
