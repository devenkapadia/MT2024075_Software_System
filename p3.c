// 3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call

#include <stdio.h>
#include <fcntl.h>

int main(){
    char *filename = "problem2.txt";

    int fd= creat(filename, 0644);

    if(fd==-1){
        perror("clear");
        return 1;
    }

    printf("File Descriptor Value is: %d\n", fd);
}
