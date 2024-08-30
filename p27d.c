/*

Name: p27d.c
Author: Kapadia Deven
Description: Write a program to execute ls -Rl by the following system calls
            d. execv
Date: 30 Aug, 2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *cmd = "/bin/ls";

    char *args[] = {"ls", "-Rl", NULL};

    if (execv(cmd, args) == -1) {
        perror("execv failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*

total 580
-rw-rw-r-- 1 deven deven    35 Aug 29 08:51 file_to_lock.txt
-rw-r--r-- 1 deven deven     0 Aug 20 19:55 infinite1.txt
-rw-r--r-- 1 deven deven     0 Aug 20 19:55 infinite2.txt
-rw-r--r-- 1 deven deven     0 Aug 20 19:55 infinite3.txt
-rw-r--r-- 1 deven deven     0 Aug 20 19:55 infinite4.txt
-rw-r--r-- 1 deven deven     0 Aug 20 19:55 infinite5.txt
-rwxrwxr-x 1 deven deven 16168 Aug 29 09:16 p10
-rw-rw-r-- 1 deven deven   826 Aug 29 09:16 p10.c
-rw-r--r-- 1 deven deven    30 Aug 29 09:16 p10test.txt
-rwxrwxr-x 1 deven deven 16248 Aug 20 22:21 p11
-rw-rw-r-- 1 deven deven  1165 Aug 20 22:14 p11.c
-rw-r--r-- 1 deven deven   130 Aug 20 22:22 p11test.txt
-rwxrwxr-x 1 deven deven 16128 Aug 20 22:22 p12
-rw-rw-r-- 1 deven deven   751 Aug 20 22:21 p12.c
-rw-rw-r-- 1 deven deven    25 Aug 20 22:21 p12test.txt
-rwxrwxr-x 1 deven deven 16088 Aug 20 22:53 p13
-rw-rw-r-- 1 deven deven   814 Aug 20 22:54 p13.c
-rwxrwxr-x 1 deven deven 16096 Aug 20 22:40 p14
-rw-rw-r-- 1 deven deven  1006 Aug 20 22:40 p14.c
-rw-rw-r-- 1 deven deven    25 Aug 20 22:40 p14test.txt
-rwxrwxr-x 1 deven deven 16032 Aug 20 22:42 p15
-rw-rw-r-- 1 deven deven   315 Aug 20 22:42 p15.c
-rwxrwxr-x 1 deven deven 16352 Aug 29 10:28 p16
-rw-rw-r-- 1 deven deven   683 Aug 29 10:28 p16.c
-rw-rw-r-- 1 deven deven     0 Aug 29 10:21 p16file.txt
drwxrwxr-x 2 deven deven  4096 Aug 29 10:58 p17
drwxrwxr-x 2 deven deven  4096 Aug 29 11:22 p18
-rwxrwxr-x 1 deven deven 16032 Aug 29 11:46 p19
-rw-rw-r-- 1 deven deven   405 Aug 29 11:45 p19.c
-rwxrwxr-x 1 deven deven 15960 Aug 20 19:27 p2
-rwxrwxr-x 1 deven deven 15960 Aug 30 12:16 p20
-rw-rw-r-- 1 deven deven   186 Aug 30 12:18 p20.c
-rwxrwxr-x 1 deven deven 16128 Aug 30 12:23 p21
-rw-rw-r-- 1 deven deven   266 Aug 30 12:28 p21.c
-rwxrwxr-x 1 deven deven 16128 Aug 30 12:25 p22
-rw-rw-r-- 1 deven deven   523 Aug 30 12:25 p22.c
-rw-r--r-- 1 deven deven    55 Aug 30 12:26 p22test.txt
-rwxrwxr-x 1 deven deven 16168 Aug 30 12:30 p23
-rw-rw-r-- 1 deven deven   610 Aug 30 12:31 p23.c
-rwxrwxr-x 1 deven deven 16168 Aug 30 12:36 p24
-rw-rw-r-- 1 deven deven   793 Aug 30 12:36 p24.c
-rwxrwxr-x 1 deven deven 16224 Aug 30 12:40 p25
-rw-rw-r-- 1 deven deven  1290 Aug 30 12:40 p25.c
-rwxrwxr-x 1 deven deven 16000 Aug 30 13:40 p26
-rw-rw-r-- 1 deven deven  3660 Aug 30 13:40 p26.c
-rwxrwxr-x 1 deven deven 16088 Aug 30 12:48 p27a
-rw-rw-r-- 1 deven deven  4089 Aug 30 12:48 p27a.c
-rwxrwxr-x 1 deven deven 16088 Aug 30 12:49 p27b
-rw-rw-r-- 1 deven deven  4129 Aug 30 12:49 p27b.c
-rwxrwxr-x 1 deven deven 16088 Aug 30 12:50 p27c
-rw-rw-r-- 1 deven deven  4241 Aug 30 12:50 p27c.c
-rwxrwxr-x 1 deven deven 16096 Aug 30 13:43 p27d
-rw-rw-r-- 1 deven deven   259 Aug 30 13:43 p27d.c
-rw-rw-r-- 1 deven deven   594 Aug 30 13:29 p28.c
-rw-rw-r-- 1 deven deven   303 Aug 20 20:01 p2.c
-rwxrwxr-x 1 deven deven 16048 Aug 20 19:28 p3
-rw-rw-r-- 1 deven deven   346 Aug 20 19:30 p3.c
-rwxrwxr-x 1 deven deven 16040 Aug 20 19:40 p4
-rw-rw-r-- 1 deven deven   447 Aug 20 19:40 p4.c
-rwxrwxr-x 1 deven deven 16040 Aug 20 19:55 p5
-rw-rw-r-- 1 deven deven  1472 Aug 20 19:57 p5.c
-rwxrwxr-x 1 deven deven 16048 Aug 20 20:13 p6
-rw-rw-r-- 1 deven deven   279 Aug 22 08:13 p6.c
-rw-rw-r-- 1 deven deven    24 Aug 20 21:17 p7dest.txt
-rw-rw-r-- 1 deven deven    24 Aug 20 21:16 p7fileSrc.txt
-rwxrwxr-x 1 deven deven   318 Aug 20 21:17 p7.sh
-rwxrwxr-x 1 deven deven 16176 Aug 20 21:34 p8
-rw-rw-r-- 1 deven deven   620 Aug 20 21:48 p8.c
-rw-rw-r-- 1 deven deven   283 Aug 20 21:48 p8file.txt
-rwxrwxr-x 1 deven deven 16096 Aug 20 21:49 p9
-rw-rw-r-- 1 deven deven  1011 Aug 20 21:59 p9.c

./p17:
total 48
-rwxr--r-- 1 deven deven     4 Aug 29 10:56 db
-rwxrwxr-x 1 deven deven 16184 Aug 29 10:33 dbCreate
-rw-rw-r-- 1 deven deven   387 Aug 29 10:30 dbCreate.c
-rwxrwxr-x 1 deven deven 16392 Aug 29 10:55 locking
-rw-rw-r-- 1 deven deven   889 Aug 29 10:55 locking.c

./p18:
total 48
-rwxrwxr-x 1 deven deven 16096 Aug 29 11:17 dbCreate
-rw-rw-r-- 1 deven deven   372 Aug 29 11:17 dbCreate.c
-rwxrwxr-x 1 deven deven 16400 Aug 29 11:22 locking
-rw-rw-r-- 1 deven deven  1972 Aug 29 11:22 locking.c
-rwxr--r-- 1 deven deven    24 Aug 29 11:23 record.txt

*/