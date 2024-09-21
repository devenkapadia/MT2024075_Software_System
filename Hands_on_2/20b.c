/*
============================================================================
Name : ./20b.c
Author : Kapadia Deven
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20th Sep, 2024.
============================================================================
*/

// reader.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    int fd;
    char buffer[100];

    // Open the FIFO for reading
    fd = open(fifo, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read data from the FIFO
    read(fd, buffer, sizeof(buffer));

    // Print the data received
    printf("Received: %s\n", buffer);

    // Close the FIFO
    close(fd);

    return 0;
}
