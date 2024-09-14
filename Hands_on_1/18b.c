/*

Name: 18b.c
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
    struct
    {
        int train_no;
        int ticket_cnt;
    } db[3];

    fd = open("record.txt", O_RDWR);

    printf("Select train number: 1, 2, 3\n");
    scanf("%d", &input);

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (input - 1) * sizeof(db);
    lock.l_len = sizeof(db);
    lock.l_pid = getpid();



    while (fcntl(fd, F_SETLK, &lock) == -1)
    {
        printf("Train %d server is busy\n", input);
        sleep(5);
    }

    // Reading value of ticket number
    lseek(fd, (input - 1) * sizeof(db), SEEK_SET);
    read(fd, &db, sizeof(db));

    printf("Current ticket count: %d\n", db->ticket_cnt);

    printf("To book ticket %d, press enter\n", db->ticket_cnt);

    getchar();
    getchar();

    db->ticket_cnt++;
    lseek(fd, -1 * sizeof(db), SEEK_CUR);
    write(fd, &db, sizeof(db));

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);
    printf("Ticket booked with number %d\n", db->ticket_cnt);

    return 0;
}