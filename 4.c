/*

Name: 4.c
Author: Kapadia Deven
Description: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 26 Aug, 2024

*/

#include <stdio.h>
#include <fcntl.h>

int main(){
    char* filename = "problem2.txt";
    // int fd= open(filename, O_RDWR);

    int fd = open(filename, O_CREAT | O_EXCL, 0644);

    if(fd==-1){
        // perror("open error");
        perror("File already exists");
        return 1;
    }

    printf("File Descriptor value with O_RDWR: %d\n", fd);
}