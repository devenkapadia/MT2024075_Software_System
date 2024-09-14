/*

Name: 11.c
Author: Kapadia Deven
Description: Write a program to open a file, duplicate the file descriptor and append the file with both the
            descriptors and check whether the file is updated properly or not.
            a. use dup
            b. use dup2
            c. use fcntl
Date: 26 Aug, 2024

*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd, fd_dup1, fd_dup2;
    char *data1 = "Data from original descriptor.\n";
    char *data2 = "Data from duplicated descriptor.\n";

    // Open the file for appending and writing
    fd = open("p11test.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    fd_dup1 = dup(fd);

    fd_dup2 = dup2(fd, fd + 1); 

    int fd_dup3 = fcntl(fd, F_DUPFD, fd + 2); 

    // Write to the file using the original file descriptor
    write(fd, data1, strlen(data1));

    // Write to the file using the duplicated file descriptors
    write(fd_dup1, data2, strlen(data2));
    write(fd_dup2, data2, strlen(data2));
    write(fd_dup3, data2, strlen(data2));

    // Close all file descriptors
    close(fd);
    close(fd_dup1);
    close(fd_dup2);
    close(fd_dup3);

    return 0;
}
