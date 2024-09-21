/*
============================================================================
Name : ./19e.c
Author : Kapadia Deven
Description : 19. Create a FIFO file by
            e. mkfifo library function
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    } else {
        printf("FIFO created successfully using mkfifo library function.\n");
    }

    return 0;
}
