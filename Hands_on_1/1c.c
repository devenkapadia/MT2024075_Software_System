/*

Name: 1c.c
Author: Kapadia Deven
Description: Create the following types of a files using (i) shell command (ii) system call
                c. FIFO (mkfifo Library Function or mknod system call)
Date: 26 Aug, 2024

*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("myFifo", 0666) == -1) {
        perror("mkfifo");
        return 1;
    }
    printf('Named Pipe created Successfully');
    return 0;
}

/*

Shell command: mkfifo fifo_name

*/