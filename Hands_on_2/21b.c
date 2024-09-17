#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO1 "/tmp/fifo1"
#define FIFO2 "/tmp/fifo2"

int main() {
    int fd_read, fd_write;
    char buffer[256], message[256];

    // Open FIFO1 for reading
    fd_read = open(FIFO1, O_RDONLY);
    if (fd_read == -1) {
        perror("open read FIFO1");
        exit(EXIT_FAILURE);
    }

    // Open FIFO2 for writing
    fd_write = open(FIFO2, O_WRONLY);
    if (fd_write == -1) {
        perror("open write FIFO2");
        exit(EXIT_FAILURE);
    }

    // Read message from parent through FIFO1
    read(fd_read, buffer, sizeof(buffer));
    printf("Child received: %s\n", buffer);

    // Write response to parent through FIFO2
    strcpy(message, "Hello from child");
    write(fd_write, message, strlen(message) + 1);

    // Close the FIFOs
    close(fd_read);
    close(fd_write);

    return 0;
}
