/*

Name: p12.c
Author: Kapadia Deven
Description: Write a program to find out the opening mode of a file. Use fcntl.
Date: 26 Aug, 2024

*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, access_mode;

    fd = open("p12test.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    int flags = fcntl(fd, F_GETFL);

    access_mode = flags & O_ACCMODE;

    if (access_mode == O_RDONLY) {
        printf("File is opened in read-only mode.\n");
    } else if (access_mode == O_WRONLY) {
        printf("File is opened in write-only mode.\n");
    } else if (access_mode == O_RDWR) {
        printf("File is opened in read-write mode.\n");
    } else {
        printf("Unknown file access mode.\n");
    }

    close(fd);
    return 0;
}
