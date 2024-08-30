/*

Name: p8.c
Author: Kapadia Deven
Description: Write a program to open a file in read only mode, read line by line and display each line as it is read.
            Close the file when end of file is reached.
Date: 26 Aug, 2024

*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("p8file.txt", O_RDONLY);  
    char buffer[256];                
    ssize_t n;

    // Check if the file was opened successfully
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((n = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';  
        printf("%s", buffer);
    }

    close(fd);

    return 0;
}
