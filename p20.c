/*

Name: p20.c
Author: Kapadia Deven
Description: Find out the priority of your running program. Modify the priority with nice command.
Date: 29 Aug, 2024

*/

#include <stdio.h>

int main() {
    while (1) {
        sleep(1); 
    }
    return 0;
}


// ps -o pid,comm,nice -p 6313


//     PID COMMAND          NI
//    6313 p20               0