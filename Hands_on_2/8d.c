#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigalrm_handler(int sig) {
    printf("Caught SIGALRM: Timer expired\n");
}

int main() {
    signal(SIGALRM, sigalrm_handler);

    // Set an alarm to go off in 5 seconds
    alarm(5);

    // Infinite loop to wait for the alarm
    while (1);

    return 0;
}
