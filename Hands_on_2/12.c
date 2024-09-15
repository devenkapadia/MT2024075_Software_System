#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        sleep(1); 
        printf("Child sending SIGKILL to parent (PID: %d)\n", getppid());
        kill(getppid(), SIGKILL);
        while (1) {
            sleep(5); 
        }
    } else if (pid > 0) {
        // Parent process
        printf("Parent process (PID: %d) exiting\n", getpid());
        exit(0);
    } else {
        perror("fork");
        exit(1);
    }
}
