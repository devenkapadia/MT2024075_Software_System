/*

Name: p6.c
Author: Kapadia Deven
Description: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 26 Aug, 2024

*/
#include <unistd.h>

int main(){
    char buffer[10];
    int input = read(0, buffer, sizeof(buffer));
    printf("%d\n", input);
    write(1, buffer, input);

    return 0;
}