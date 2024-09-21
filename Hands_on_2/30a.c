/*
============================================================================
Name : ./30a.c
Author : Kapadia Deven
Description : Write a program to create a shared memory.
            a. write some data to the shared memory
Date: 20th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);

    // Create a shared memory segment
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    char *str = (char*) shmat(shmid, NULL, 0);

    printf("Writing data to shared memory...\n");
    strcpy(str, "Hello, shared memory!");

    shmdt(str);

    printf("Data written to shared memory.\n");

    return 0;
}
