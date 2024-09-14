#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigvtalrm_handler(int sig) {
    printf("Caught SIGVTALRM: Virtual timer expired\n");
}

int main() {
    signal(SIGVTALRM, sigvtalrm_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 3;     // Timer goes off after 3 seconds
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  // No repeat interval
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    // Busy loop to simulate CPU-bound task, as virtual timer only counts during CPU execution
    while (1);

    return 0;
}
