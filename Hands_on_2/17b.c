/*
============================================================================
Name : ./17b.c
Author : Kapadia Deven
Description : Write a program to execute ls -l | wc.
            b. use dup2
Date: 20th Sep, 2024.
============================================================================
*/

#include <unistd.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    if (fork() == 0) {  // Child process: execute `ls -l`
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        execlp("ls", "ls", "-l", NULL);
    } else {  // Parent process: execute `wc`
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        execlp("wc", "wc", NULL);
    }
}
