/*

Name: 17b.c
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

    // Initialize the lock structure
    lock.l_type = F_WRLCK;  // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  // Lock the entire file

    while(fcntl(fd, F_SETLK, &lock)==-1){
        printf("Server is busy\n");
        sleep(5);
    }

    printf("Booking your ticket\n");

    read(fd, &db, sizeof(db));
    printf("Your Ticket No: %d\n", db.ticket_no);
    db.ticket_no++;

    lseek(fd, 0, SEEK_SET);
    write(fd, &db, sizeof(db));

    printf("Press Enter to Proceed\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Ticket Bookes Successfully\n");

    close(fd);

    //checking the final value of ticket no.
        fd=open("db", O_RDONLY);
        read(fd, &db, sizeof(db));

        printf("Next TIcket no.: %d\n", db.ticket_no);
        close(fd);   
    return 0;
}