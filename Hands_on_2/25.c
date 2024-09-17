#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok(".", 'b');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Access permissions: %o\n", buf.msg_perm.mode);

    // UID and GID
    printf("UID: %d\n", buf.msg_perm.uid);
    printf("GID: %d\n", buf.msg_perm.gid);

    // Time of last message sent
    printf("Time of last message sent: %s", ctime(&buf.msg_stime));

    // Time of last message received
    printf("Time of last message received: %s", ctime(&buf.msg_rtime));

    // Time of last change in the message queue
    printf("Time of last change: %s", ctime(&buf.msg_ctime));

    // Current size of the queue (in bytes)
    printf("Current number of bytes in queue: %lu\n", buf.__msg_cbytes);

    // Number of messages in the queue
    printf("Number of messages in queue: %lu\n", buf.msg_qnum);

    // Maximum number of bytes allowed in the queue
    printf("Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);

    // PID of the last msgsnd
    printf("PID of last msgsnd: %d\n", buf.msg_lspid);

    // PID of the last msgrcv
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}
