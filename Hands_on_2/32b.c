/*
============================================================================
Name : ./32b.c
Author : Kapadia Deven
Description : Write a program to implement semaphore to protect any critical section.
            b. protect shared memory from concurrent write access
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

void sem_wait(int semid) {
    struct sembuf sb = {0, -1, 0};  
    semop(semid, &sb, 1);
}

void sem_signal(int semid) {
    struct sembuf sb = {0, 1, 0};  
    semop(semid, &sb, 1);
}

int main() {
    key_t key = ftok("shmfile", 65);

    int semid = semget(key, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 1);  

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *data = (char *)shmat(shmid, NULL, 0);

    sem_wait(semid); 

    printf("Writing data to shared memory...\n");
    strcpy(data, "Shared memory protected by semaphore.");

    sem_signal(semid); 

    shmdt(data);

    printf("Data written to shared memory.\n");

    return 0;
}
