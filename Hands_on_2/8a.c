#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigsegv_handler(int sig) {
    signal(sig, sigsegv_handler);
    printf("Caught SIGSEGV: Segmentation fault\n Singal Number is %d\n", sig); 
    exit(1);
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    int *ptr = NULL;
    *ptr = 42;
    // ptr points to  NULL location and it is trying to write 42 in the NULL location  
    // this will lead to segmentation fault

    return 0;
}
