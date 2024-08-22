// 5. Write a program to create five new files with infinite loop. Execute the program in the background
// and check the file descriptor table at /proc/pid/fd.

#include <stdio.h>
#include <fcntl.h>

int main(){
    int fds[5];
    char* fnames[5] = {"infinite1.txt", "infinite2.txt", "infinite3.txt", "infinite4.txt", "infinite5.txt"};

    for (int i = 0; i < 5; i++) {
        fds[i] = open(fnames[i], O_CREAT | O_RDWR | O_EXCL, 0644);
        if (fds[i] == -1) {
            perror("Error opening file");
        } else {
            printf("Created file: %s with file descriptor: %d\n", fnames[i], fds[i]);
        }
    }

    while(1);

}

/*
OUTPUT

./p5 &
[1] 6687

cd /proc/6687/fd
ll
total 0
dr-x------ 2 deven deven  8 Aug 20 19:56 ./
dr-xr-xr-x 9 deven deven  0 Aug 20 19:56 ../
lrwx------ 1 deven deven 64 Aug 20 19:56 0 -> /dev/pts/1
lrwx------ 1 deven deven 64 Aug 20 19:56 1 -> /dev/pts/1
lrwx------ 1 deven deven 64 Aug 20 19:56 2 -> /dev/pts/1
lrwx------ 1 deven deven 64 Aug 20 19:56 3 -> '/home/deven/Study IIITB/SS/SS_Hands_on/infinite1.txt'
lrwx------ 1 deven deven 64 Aug 20 19:56 4 -> '/home/deven/Study IIITB/SS/SS_Hands_on/infinite2.txt'
lrwx------ 1 deven deven 64 Aug 20 19:56 5 -> '/home/deven/Study IIITB/SS/SS_Hands_on/infinite3.txt'
lrwx------ 1 deven deven 64 Aug 20 19:56 6 -> '/home/deven/Study IIITB/SS/SS_Hands_on/infinite4.txt'
lrwx------ 1 deven deven 64 Aug 20 19:56 7 -> '/home/deven/Study IIITB/SS/SS_Hands_on/infinite5.txt'

*/