#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static inline unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    int i;

    start = rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();

    printf("Time taken for 100 getppid() calls: %llu cycles\n", end - start);

    return 0;
}
