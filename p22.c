/*

Name: p22.c
Author: Kapadia Deven
Description: Write a program, open a file, call fork, and then write to the file by both the child as well as the
            parent processes. Check output of the file.
Date: 29 Aug, 2024

*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;

    fd = open("p22test.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);

    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        dprintf(fd, "This is the child process.\n");
    } else {
        dprintf(fd, "This is the parent process.\n");
    }

    close(fd);

    return 0;
}
