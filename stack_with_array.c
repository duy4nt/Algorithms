#include <stdio.h>

#define MAXLEN 1000

void push(int stack[], int elem);
int pop(int stack[]);
int peek(int stack[]);

main() {
    int arr[MAXLEN];
}

void push(int s[], int n) {
    int i;
    i = 0;

    while(s[i] != '\0') {
        ++i;
    }

    if ((i+2) < MAXLEN) {
        s[i+1] = n;
        s[i+2] = '\0';
    } else {
        printf("not enough space");
        return;
    }
}

int pop(int s[]) {
    int i, pop;
    i = 0;

    while(s[i] != '\0') {
        ++i;
    }
    
    if (i > 0) {
        pop = s[i];
        s[i] = '\0';
        s[++i] = NULL;
    } else {
        printf("empty stack");
        return 1;
    }

    return pop;
}

int peek(int s[]) {
    int i, peek;
    i = 0;

    while(s[i] != '\0') {
        ++i;
    }
    
    if (i > 0) {
        peek = s[i];
    } else {
        printf("empty stack");
        return 1;
    }

    return peek;
}

