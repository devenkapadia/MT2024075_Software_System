/*

Name: p16.c
Author: Kapadia Deven
Description: Write a program to perform mandatory locking.
            a. Implement write lock
            b. Implement read lock
Date: 26 Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


int main(){
    struct flock lock;

    int fd=open("p16file.txt", O_CREAT | O_RDWR, 0666);
    if(fd==-1){
        perror("error occured");
        exit(1);
    }

    lock.l_type=F_WRLCK;
    // lock.l_type=F_RDLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_pid=getpid();

    printf("Outside CS\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Acquiring lock....\n");
    sleep(5);
    printf("Inside CS\n");
    printf("Press enter to unlock\n");

    getchar();
    printf("File unlocked");
    lock.l_type=F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    return 0;
}