#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigfpe_handler(int sig) {
    printf("Caught SIGFPE: Floating-point exception\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);

    // Trigger division by zero to cause SIGFPE
    int x = 5 / 0;

    return 0;
}
