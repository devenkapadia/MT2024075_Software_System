/*
============================================================================
Name : ./30c.c
Author : Kapadia Deven
Description : Write a program to create a shared memory.
            c. detach the shared memory
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, 1024, 0666);

    char *str = (char*) shmat(shmid, NULL, 0);

    printf("Detaching shared memory...\n");
    shmdt(str);
    printf("Shared memory detached.\n");

    return 0;
}
