#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int sig) {
    printf("Caught SIGFPE: Divide by zero\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);
    // Exceptions include overflows, under-flows, and division by zero.

    int x = 5 / 0;

    return 0;
}
