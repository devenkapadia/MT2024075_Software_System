/*

Name: 23.c
Author: Kapadia Deven
Description: Write a program to create a Zombie state of the running program.
Date: 29 Aug, 2024

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        printf("In child - PID = %d\n", getpid());
        _exit(0); 
    } else {
        printf("This is parent process %d\n", getpid());
        sleep(30); // Sleep for 30 seconds, during which child is a zombie
        wait(NULL);
    }

    return 0;
}

// USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
// deven       7248  0.0  0.0      0     0 pts/0    Z+   12:30   0:00 [p23] <defunct>
// deven       7325  0.0  0.0   9072  2304 pts/1    S+   12:31   0:00 grep --color=auto Z