#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT (just for notification when the signal is caught)
void sigint_ignore_handler(int sig) {
    printf("SIGINT ignored, press Ctrl+C again to terminate.\n");
}

int main() {
    signal(SIGINT, sigint_ignore_handler);
    printf("SIGINT is now being ignored. Press Ctrl+C.\n");
    
    // Wait for 5 seconds while ignoring SIGINT
    sleep(5);

    // Reset SIGINT to default action
    printf("Resetting SIGINT to default action. Press Ctrl+C to terminate.\n");
    signal(SIGINT, SIG_DFL);

    // Wait for the next SIGINT, now it will terminate the process
    while (1) {
        pause();  // Wait for signals
    }

    return 0;
}
