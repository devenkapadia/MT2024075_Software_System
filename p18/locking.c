/*

Name: p18/dbCreate.c
Author: Kapadia Deven
Description: Write a program to perform Record locking.
            a. Implement write lock
            b. Implement read lock
            Create three records in a file. Whenever you access a particular record, first lock it then modify/access
            to avoid race condition.
Date: 29 Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, input;
    struct {
        int train_no;
        int ticket_cnt;
    } db[3];

    fd = open("record.txt", O_RDWR);

    printf("Select train number: 1, 2, 3\n");
    scanf("%d", &input);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
        // Record for train number 1 is stored at the beginning of the file
        // so at offset = 0
                       // For train number 2, it is stored at offset = sizeof(db)
                       // For train number 3, it is stored at offset = 2 * sizeof(db)
                       // And that is essentially what this next line does
    lock.l_start = (input - 1) * sizeof(db);
    // This actually implements record-level locking
    // We start locking from the beginning of selected train's record
    // upto the end of that record which will be at l_start + sizeof(db)
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();

    // Reading value of ticket number
    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));

    printf("Before entering critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Current ticket count: %d\n", db->ticket_cnt);
    db->ticket_cnt++;
    // Currently fd is pointing to end of current record and we have to
    // move it to the start of current record, i.e.SEEK_CUR - sizeof(db)
                                                // Or you can just do SEEK_SET + (input - 1) * sizeof(db)
    
    lseek(fd, -1 * sizeof(db), SEEK_CUR);
    write(fd, &db, sizeof(db));
    printf("To book ticket, press enter\n");
    getchar();
    // First getchar() call will be bypassed by train number input on
    // STDIN, so that's why we add another getchar() call here getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Ticket booked with number %d\n", db->ticket_cnt);

    return 0;
}