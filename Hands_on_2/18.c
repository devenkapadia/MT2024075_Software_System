/*
============================================================================
Name : ./18.c
Author : Kapadia Deven
Description : Write a program to find out total number of directories on the pwd.
            execute ls -l | grep ^d | wc ? Use only dup2.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd1[2], pipefd2[2];
    pid_t pid1, pid2;

    // Create first pipe for "ls -l | grep ^d"
    if (pipe(pipefd1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

    // Create second pipe for "grep ^d | wc -l"
    if (pipe(pipefd2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    // Fork first child for "ls -l"
    if ((pid1 = fork()) == -1) {
        perror("fork1");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // First child process: execute "ls -l"
        close(pipefd1[0]);  // Close the read end of the first pipe
        dup2(pipefd1[1], STDOUT_FILENO);  // Redirect stdout to pipe1's write end
        close(pipefd1[1]);  // Close pipe1 write end after duplicating
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    } 

    // Fork second child for "grep ^d"
    if ((pid2 = fork()) == -1) {
        perror("fork2");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        // Second child process: execute "grep ^d"
        close(pipefd1[1]);  // Close the write end of pipe1
        dup2(pipefd1[0], STDIN_FILENO);  // Redirect stdin to pipe1's read end
        close(pipefd1[0]);  // Close pipe1 read end after duplicating

        close(pipefd2[0]);  // Close the read end of pipe2
        dup2(pipefd2[1], STDOUT_FILENO);  // Redirect stdout to pipe2's write end
        close(pipefd2[1]);  // Close pipe2 write end after duplicating

        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep");
        exit(EXIT_FAILURE);
    }

    // Parent process: execute "wc -l"
    close(pipefd1[0]);  // Close pipe1 read end in the parent
    close(pipefd1[1]);  // Close pipe1 write end in the parent

    close(pipefd2[1]);  // Close the write end of pipe2
    dup2(pipefd2[0], STDIN_FILENO);  // Redirect stdin to pipe2's read end
    close(pipefd2[0]);  // Close pipe2 read end after duplicating

    execlp("wc", "wc", "-l", NULL);
    perror("execlp wc");
    exit(EXIT_FAILURE);

    return 0;
}
