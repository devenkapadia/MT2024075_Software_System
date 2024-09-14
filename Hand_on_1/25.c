/*

Name: 25.c
Author: Kapadia Deven
Description: Write a program to create three child processes. The parent should wait for a particular child (use
            waitpid system call).
Date: 29 Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;
    int status;
    pid1 = fork();
    if (pid1 == 0) {
        printf("First child (PID: %d) is running.\n", getpid());
        sleep(2); 
        printf("First child (PID: %d) is exiting.\n", getpid());
        exit(0);  
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("Second child (PID: %d) is running.\n", getpid());
        sleep(4); 
        printf("Second child (PID: %d) is exiting.\n", getpid());
        exit(0);  
    }

    pid3 = fork();
    if (pid3 == 0) {
        printf("Third child (PID: %d) is running.\n", getpid());
        sleep(6); 
        printf("Third child (PID: %d) is exiting.\n", getpid());
        exit(0); 
    }

    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    // waitpid(pid3, &status, 0);

    printf("Parent process (PID: %d) is exiting after firts two children have finished.\n", getpid());
}


// First child (PID: 8055) is running.
// Second child (PID: 8056) is running.
// Third child (PID: 8057) is running.
// First child (PID: 8055) is exiting.
// Second child (PID: 8056) is exiting.
// Parent process (PID: 8054) is exiting after all children have finished.
// Third child (PID: 8057) is exiting.