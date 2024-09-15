#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sigprof_handler(int sig) {
    printf("Caught SIGPROF: Profiling timer expired\n");
}

int main() {
    signal(SIGPROF, sigprof_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;     
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;  
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1);

    return 0;
}
