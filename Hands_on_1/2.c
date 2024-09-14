/*

Name: 2.c
Author: Kapadia Deven
Description: Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
            identify all the process related information in the corresponding proc directory.
Date: 26 Aug, 2024

*/



#include <stdio.h>

int main() {
    while (1) {
        sleep(1); 
    }
    return 0;
}

/*
./p2 &
[1] 6812
*/