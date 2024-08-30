/*

Name: p26.c
Author: Kapadia Deven
Description: Write a program to execute an executable program.
            b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 29 Aug, 2024

*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Pls provide name\n");
        return 1;
    }
    printf("Good Morning, %s!\n", argv[1]);
    return 0;
}
