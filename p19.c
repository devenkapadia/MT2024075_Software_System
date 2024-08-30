#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc( ){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A"(dst));
}

int main(){
    int i, nano;
    unsigned long long int start, end;
    start=rdtsc();
    for(int i=0; i<10000; i++){
        getppid();
    }
    end=rdtsc();
    nano=(end-start)/2.09;

    printf("The fun takes %d nano sec", nano);
}