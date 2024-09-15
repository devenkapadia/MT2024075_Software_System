#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    int pid;
    printf("Enter PID of the first program: ");
    scanf("%d", &pid);

    printf("Sending SIGSTOP to process %d\n", pid);
    kill(pid, SIGSTOP);  // Send SIGSTOP

    return 0;
}
