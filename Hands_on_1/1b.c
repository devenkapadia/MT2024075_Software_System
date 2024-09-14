/*

Name: 1b.c
Author: Kapadia Deven
Description: Create the following types of a files using (i) shell command (ii) system call
                b. hard link (link system call)
Date: 26 Aug, 2024

*/

#include <stdio.h>
#include <unistd.h>

int main() {
    if (link("/home/deven/Study IIITB/SS/", "hardLink") == -1) {
        perror("link");
        return 1;
    }
    printf("Hard link created successfully!\n");
    return 0;
}



/*

Shell command: ln target_file hardlink_name

*/