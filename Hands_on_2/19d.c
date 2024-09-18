
/*
mknod myfifo p

mkfifo myfifo

strace mknod myfifo p
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (mknod("myfifo", 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    } else {
        printf("FIFO created successfully using mknod system call.\n");
    }

    return 0;
}
