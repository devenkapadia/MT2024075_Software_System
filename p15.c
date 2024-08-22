// 15. Write a program to display the environmental variable of the user (use environ).

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
