/*
============================================================================
Name : ./17c.c
Author : Kapadia Deven
Description : Write a program to execute ls -l | wc.
            c. use fcntl
Date: 20th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    if (fork() == 0) {  // Child process: execute `ls -l`
        close(pipefd[0]);
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
        execlp("ls", "ls", "-l", NULL);
    } else {  // Parent process: execute `wc`
        close(pipefd[1]);
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
        execlp("wc", "wc", NULL);
    }
}
