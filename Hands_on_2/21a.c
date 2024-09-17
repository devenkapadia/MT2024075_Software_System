#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

int main() {
    int fd_write, fd_read;
    char message[256], buffer[256];

    // Create the FIFOs
    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    // Open FIFO1 for writing
    fd_write = open(FIFO1, O_WRONLY);
    if (fd_write == -1) {
        perror("open write FIFO1");
        exit(EXIT_FAILURE);
    }

    // Open FIFO2 for reading
    fd_read = open(FIFO2, O_RDONLY);
    if (fd_read == -1) {
        perror("open read FIFO2");
        exit(EXIT_FAILURE);
    }

    // Write message to child through FIFO1
    strcpy(message, "Hello from parent");
    write(fd_write, message, strlen(message) + 1);

    // Read response from child through FIFO2
    read(fd_read, buffer, sizeof(buffer));
    printf("Parent received: %s\n", buffer);

    // Close the FIFOs
    close(fd_write);
    close(fd_read);

    return 0;
}
