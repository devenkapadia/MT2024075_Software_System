/*

Name: p1a.c
Author: Kapadia Deven
Description: Create the following types of a files using (i) shell command (ii) system call
                a. soft link (symlink system call)
Date: 26 Aug, 2024

*/

#include <stdio.h>
#include <unistd.h>

int main() {
    if (symlink("/home/deven/Study IIITB/SS/", "symLink") == -1) {
        perror("symlink");
        return 1;
    }
    return 0;
}


/*

Shell command: ln -s target_file symlink_name

*/