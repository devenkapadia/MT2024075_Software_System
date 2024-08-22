// 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
// bytes (use lseek) and write again 10 bytes.
// a. check the return value of lseek
// b. open the file with od and check the empty spaces in between the data.

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *data1 = "ABCDEFGHIJ";  // First 10 bytes
    char *data2 = "KLMNOPQRST";  // Second 10 bytes

    fd = open("p10test.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    write(fd, data1, 10);

    off_t result = lseek(fd, 10, SEEK_CUR);

    write(fd, data2, 10);

    close(fd);

    return 0;
}
