/*
============================================================================
Name : ./30b.c
Author : Kapadia Deven
Description : Write a program to create a shared memory.
            b. attach with O_RDONLY and check whether you are able to overwrite.
Date: 20th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key = ftok("shmfile", 65);

    int shmid = shmget(key, 1024, 0666);

    // Attach the shared memory segment in read-only mode
    char *str = (char*) shmat(shmid, NULL, SHM_RDONLY);

    printf("Trying to overwrite data in read-only mode...\n");
    strcpy(str, "New data"); // This will cause an error

    shmdt(str);

    return 0;
}
