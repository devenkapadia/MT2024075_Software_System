/*

Name: p26.c
Author: Kapadia Deven
Description: Write a program to execute an executable program.
            a. use some executable program
Date: 29 Aug, 2024

*/

#include<stdio.h>
#include<unistd.h>

int main()
{
    execl("/usr/bin/ls","ls","-l",NULL);
    printf("Execl failed to execute\n");
    return 0;
}