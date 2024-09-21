/*
============================================================================
Name : ./20a.c
Author : Kapadia Deven
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20th Sep, 2024.
============================================================================
*/

// writer.c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *fifo = "/tmp/myfifo";
    int fd;
    
    // Create the FIFO (named pipe)
    if (mkfifo(fifo, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fd = open(fifo, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    const char *message = "Hello from writer!";

    write(fd, message, strlen(message)+1);
    printf("Written to file with fd=%d\n", fd);

    // Close the FIFO
    close(fd);

    return 0;
}


// run rm /tmp/myfifo everytime to delete created pipe