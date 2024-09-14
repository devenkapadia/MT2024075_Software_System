/*

Name: 24.c
Author: Kapadia Deven
Description: Write a program to create an orphan process.
Date: 29 Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) created.\n", getpid());
        sleep(5);  
        printf("Child process (PID: %d) is now orphaned as the parent has exited.\n", getpid());
    } else {
        printf("Parent process (PID: %d) exiting...\n", getpid());
        exit(0); 
    }

    return 0;
}


// Parent process (PID: 7584) exiting...
// Child process (PID: 7585) created.
// deven@deven-ROG-Strix-G512LI-G512LI:~/Study IIITB/SS/SS_Hands_on$ Child process (PID: 7585) is now orphaned as the parent has exited.