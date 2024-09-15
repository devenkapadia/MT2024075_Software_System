#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    signal(SIGSTOP, handle_signal);  // Attempt to catch SIGSTOP (this won't work)

    printf("Waiting to catch SIGSTOP (but it won't work)...\n");
    while (1) {
        sleep(1);  // Keep the process running
    }

    return 0;
}
