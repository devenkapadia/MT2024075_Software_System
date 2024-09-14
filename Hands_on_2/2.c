#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void print_rlimit(int resource, const char *name) {
    struct rlimit limit;
    
    if (getrlimit(resource, &limit) == 0) {
        printf("%-20s: Soft Limit = %lu, Hard Limit = %lu\n", name, limit.rlim_cur, limit.rlim_max);
    } else {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
}

int main() {
    print_rlimit(RLIMIT_CPU, "CPU Time (seconds)");
    print_rlimit(RLIMIT_FSIZE, "Max File Size (bytes)");
    print_rlimit(RLIMIT_DATA, "Max Data Segment Size (bytes)");
    print_rlimit(RLIMIT_STACK, "Max Stack Size (bytes)");
    print_rlimit(RLIMIT_CORE, "Max Core File Size (bytes)");
    print_rlimit(RLIMIT_RSS, "Max Resident Set Size (bytes)");
    print_rlimit(RLIMIT_NOFILE, "Max Number of Open Files");
    print_rlimit(RLIMIT_MEMLOCK, "Max Locked Memory (bytes)");
    print_rlimit(RLIMIT_AS, "Max Address Space (bytes)");
    print_rlimit(RLIMIT_NPROC, "Max Number of Processes");
    print_rlimit(RLIMIT_LOCKS, "Max Number of File Locks");

    return 0;
}
