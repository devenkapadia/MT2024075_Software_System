/*
============================================================================
Name : ./32a.c
Author : Kapadia Deven
Description : Write a program to implement semaphore to protect any critical section.
            a. rewrite the ticket number creation program using semaphore
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
    semctl(semid, 0, SETVAL, 1);  

    int ticket = 0;  

    while (ticket < 5) {
        sem_wait(semid);  

        ticket++;
        printf("Ticket number created: %d\n", ticket);

        sem_signal(semid);  
        sleep(1); 
    }

    return 0;
}
