/*
============================================================================
Name : ./31b.c
Author : Kapadia Deven
Description : Write a program to create a semaphore and initialize value to the semaphore.
            a. create a binary semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key = ftok("semfile", 65);

    int semid = semget(key, 1, 0666 | IPC_CREAT);

    semctl(semid, 0, SETVAL, 5);

    printf("Counting semaphore created and initialized to 5.\n");

    return 0;
}
