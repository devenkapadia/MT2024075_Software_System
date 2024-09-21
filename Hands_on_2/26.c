/*
============================================================================
Name : ./26.c
Author : Kapadia Deven
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 100

struct msg_buffer {
    long msg_type;
    char msg_text[MAX_TEXT];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

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

    message.msg_type = 1; // Message type must be > 0
    printf("Enter message to send: ");
    fgets(message.msg_text, MAX_TEXT, stdin);
    message.msg_text[strcspn(message.msg_text, "\n")] = '\0'; // Remove newline

    if (msgsnd(msgid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s\n", message.msg_text);

    return 0;
}
