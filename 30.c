/*

Name: 30.c
Author: Kapadia Deven
Description: Write a program to run a script at a specific time using a Daemon process.
Date: 30 Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if(!fork()){
        setsid();
        chdir("/");
        umask(0);

        while(1){
            printf("daemon is performing tasks\n");
            fflush(stdout); 
            sleep(10);
        } 
    } else{
        exit(0);
    }
    return 0;
}
