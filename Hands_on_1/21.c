/*

Name: 21.c
Author: Kapadia Deven
Description: Write a program, call fork and print the parent and child process id.
Date: 29 Aug, 2024

*/

#include<stdio.h>

int main()
{
    if (!fork())
    {
        printf("In child - PID = %d\n", getpid());
    }
    else
    {
        printf("This is parent process %d\n", getpid());
        wait(0);
    }
}


// This is parent process 6783
// In child - PID = 6784