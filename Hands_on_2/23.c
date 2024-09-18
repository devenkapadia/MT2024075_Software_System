#include <stdio.h>
#include <unistd.h>

int main() {

    long max_files = sysconf(_SC_OPEN_MAX);
    printf("Maximum number of open files: %ld\n", max_files);

    return 0;
}
