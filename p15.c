/*

Name: p15.c
Author: Kapadia Deven
Description: Write a program to display the environmental variable of the user (use environ).
Date: 26 Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>

extern char **environ;  // Declare the extern variable

int main() {
    char **env;

    for (env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}
