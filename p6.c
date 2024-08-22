// 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

#include <unistd.h>

int main(){
    char buffer[10];
    int input = read(0, buffer, sizeof(buffer));
    printf("%d\n", input);
    write(1, buffer, input);

    return 0;
}