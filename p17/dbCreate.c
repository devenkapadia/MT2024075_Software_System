#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd;
    struct {
        int ticket_no;
    } db;

    db.ticket_no=10;
    fd=open("db", O_CREAT | O_RDWR, 0744);
    write(fd, &db, sizeof(db));
    close(fd);

    fd=open("db", O_RDONLY);
    read(fd, &db, sizeof(db));

    printf("TIcket no.: %d", db.ticket_no);
    close(fd);    
}