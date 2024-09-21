/*
============================================================================
Name : ./22.c
Author : Kapadia Deven
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
            system call with FIFO.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_PATH "/tmp/myfifo"

int main() {
    int fd;
    fd_set read_fds;
    struct timeval timeout;
    char buffer[256];
    int ret;

    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
    }

    fd = open(FIFO_PATH, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for data to be written to the FIFO (10 seconds)...\n");
    ret = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Timeout: No data was written to the FIFO within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &read_fds)) {
            int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                printf("Received: %s\n", buffer);
            } else {
                printf("No data read from FIFO.\n");
            }
        }
    }

    close(fd);
    unlink(FIFO_PATH);

    return 0;
}


// echo "Hello, FIFO!" > /tmp/myfifo
// In another terminal write this program to write into mkfifo