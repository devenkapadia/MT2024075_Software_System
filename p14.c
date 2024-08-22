// 14 Write a program to find the type of a file.
// a. Input should be taken from command line.
// b. program should be able to identify any type of a file.

#include <stdio.h>
#include <sys/stat.h>

int main() {
    char *filename = "p14test.txt";
    struct stat fileStat;

    if (stat(filename, &fileStat) != 0) {
        perror("Error getting file status");
        return 1;
    }

    if (S_ISREG(fileStat.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(fileStat.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(fileStat.st_mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(fileStat.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(fileStat.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISSOCK(fileStat.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }

    return 0;
}
