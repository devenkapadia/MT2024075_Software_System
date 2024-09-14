/*

Name: 1a.c
Author: Kapadia Deven
Description: Create the following types of a files using (i) shell command (ii) system call
                a. soft link (symlink system call)
Date: 26 Aug, 2024

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main() {
    struct stat sb;
    char *name = "symLink";
    if (symlink("/home/deven/Study IIITB/SS/", name) == -1) {
        perror("symlink");
        return 1;
    }
    printf("%d\n", lstat(name, &sb));
    // it prints 0 if successfully done
    return 0;
}


/*

Shell command: ln -s target_file symlink_name

*/