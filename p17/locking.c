/*

Name: p17/locking.c
Author: Kapadia Deven
Description: Write a program to simulate online ticket reservation. Implement write lock
            Write a program to open a file, store a ticket number and exit. Write a separate program, to
            open the file, implement write lock, read the ticket number, increment the number and print
            the new ticket number then close the file.
Date: 29 Aug, 2024

*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    struct flock lock;
    int fd;
    struct {
        int ticket_no;
    } db;

    fd = open("db", O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("Before CS\n");

    // Initialize the lock structure
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock the entire file

    fcntl(fd, F_SETLKW, &lock);
    printf("Inside CS\n");

    read(fd, &db, sizeof(db));
    printf("Current Ticket No: %d\n", db.ticket_no);
    db.ticket_no++;

    lseek(fd, 0, SEEK_SET);
    write(fd, &db, sizeof(db));

    printf("Press enter to unlock\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Outside CS\n");

    close(fd);
    return 0;
}