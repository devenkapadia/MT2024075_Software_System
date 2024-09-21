/*
============================================================================
Name : ./30d.c
Author : Kapadia Deven
Description : Write a program to create a shared memory.
            d. remove the shared memory
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, 1024, 0666);

    printf("Removing shared memory...\n");
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed.\n");

    return 0;
}
