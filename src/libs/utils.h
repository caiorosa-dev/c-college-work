//
// Created by caior on 04/05/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#ifndef UTILS
#define UTILS

// Retirado do Stack Overflow
int sleepMs(long milliseconds)
{
    struct timespec ts;
    int res;

    if (milliseconds < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

void animatePrintf(const char string[]) {
    sleepMs(250);
    printf("%s", string);
}

int readInt() {
    int value;

    scanf("%d", &value);
    fflush(stdin);

    return value;
}

char readChar() {
    char value;

    scanf("%c", &value);
    fflush(stdin);

    return value;
}

float readFloat() {
    float value;

    scanf("%f", &value);
    fflush(stdin);

    return value;
}

void clearTerminal() {
    system("cls");
}

#endif //UTILS

