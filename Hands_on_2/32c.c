/*
============================================================================
Name : ./32c.c
Author : Kapadia Deven
Description : Write a program to implement semaphore to protect any critical section.
            c. protect multiple pseudo resources ( may be two) using counting semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

void sem_wait(int semid) {
    struct sembuf sb = {0, -1, 0};  
    semop(semid, &sb, 1);
}

void sem_signal(int semid) {
    struct sembuf sb = {0, 1, 0}; 
    semop(semid, &sb, 1);
}

int main() {
    key_t key = ftok("semfile", 65);

    int semid = semget(key, 1, 0666 | IPC_CREAT);
    semctl(semid, 0, SETVAL, 2);  

    for (int i = 0; i < 5; i++) {
        sem_wait(semid);  

        printf("Using pseudo resource %d\n", i + 1);
        sleep(1); 

        sem_signal(semid);  
    }

    return 0;
}
