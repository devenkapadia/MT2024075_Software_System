#include <stdio.h>
#include <signal.h>

void sigint_handler(int sig) {
    printf("\nCaught SIGINT: Interrupt signal (Ctrl+C)\n");
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("Running... Press Ctrl+C to trigger SIGINT\n");
        sleep(1);
    }

    return 0;
}
