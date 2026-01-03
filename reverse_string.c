#include <stdio.h>

#define MAXLEN 1000

int getword(char word[], int len);

void reverseword(char word[], int len);

main() {
    char word[MAXLEN];
    int len;

    len = getword(word, MAXLEN);
    reverseword(word, len);
}

int getword(char word[], int len) {
    int i, c;

    for (i = 0; i < len && (c = getchar()) != '\n' && c != EOF; ++i) {
        word[i] = c;
    }

    return i + 1;
}

void reverseword(char word[], int len) {
    int i;

    for (i = len - 1; i >= 0; --i) {
        printf("%c", word[i]);
    }
    printf("\n");

