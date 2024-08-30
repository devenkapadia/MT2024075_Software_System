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

int main(){
    int i, fd;
    struct {
        int train_no;
        int ticket_cnt;
    } db[3];

    for(int i=0; i<3; i++){
        db[i].train_no=i+1;
        db[i].ticket_cnt=0;
    }

    fd=open("record.txt", O_CREAT | O_RDWR, 0744);
    write(fd, db, sizeof(db));
    close(fd);    
}