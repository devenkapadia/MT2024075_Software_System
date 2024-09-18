#include <unistd.h>

int main() {
    int pipefd[2];
    pipe(pipefd);
    if (fork() == 0) {  // Child process: execute `ls -l`
        close(pipefd[0]);
        dup(pipefd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {  // Parent process: execute `wc`
        close(pipefd[1]);
        dup(pipefd[0]);
        execlp("wc", "wc", NULL);
    }
}
