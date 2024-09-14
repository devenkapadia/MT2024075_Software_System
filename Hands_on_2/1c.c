#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

void timer_handler(int signum) {
    printf("Profile Timer expired\n");
}

int main() {
    struct itimerval timer;

    signal(SIGPROF, timer_handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1);

    return 0;
}
