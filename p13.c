// 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
// verify whether the data is available within 10 seconds or not (check in $man 2 select).

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main(void)
{
    int retval;
    fd_set rfds;
    struct timeval tv;

    /* Watch stdin (fd 0) to see when it has input. */

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);


    tv.tv_sec = 10;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don't rely on the value of tv now! */

    if (retval == -1)
        perror("select()");
    else if (retval)
        printf("Data is available now.\n");
    /* FD_ISSET(0, &rfds) will be true. */
    else
        printf("No data within ten seconds.\n");

    exit(EXIT_SUCCESS);
}
