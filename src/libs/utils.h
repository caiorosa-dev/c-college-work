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

int randomNumber(int maxNumber) {
    srand(time(NULL));

    int random = rand() % (maxNumber + 1);

    return random;
}

void animatePrintf(const char string[]) {
    sleepMs(250);
    printf("%s", string);
}

int readInt() {
    int value;

    fflush(stdin);
    scanf("%d", &value);

    return value;
}

char readChar() {
    char value;

    fflush(stdin);
    scanf("%c", &value);

    return value;
}

char* readString() {
    char *value = malloc(50 * sizeof(char));

    fgets(value, sizeof(value), stdin);
    value[strcspn(value, "\n")] = 0;

    return value;
}

float readFloat() {
    float value;

    fflush(stdin);
    scanf("%f", &value);

    return value;
}

void clearTerminal() {
    system("cls");
}

#endif //UTILS

