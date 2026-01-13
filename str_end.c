#include <stdio.h>

#define MAXLEN 1000

int get_lined(char *line);
int str_end(char *line, char *end);

int len1, len2;

main() {
    int result;

    char line[MAXLEN];
    char end[MAXLEN];

    len1 = get_lined(line);
    len2 = get_lined(end);

    result = str_end(line, end);

    if (result == 1) {
        printf("the string does occurs at the end");
    } else if (result == 0){
        printf("the string does not occur at the end");
    } else {
        printf("some erorr occured");
    }
}

int get_lined(char *s) {
    int i, c;
    i = 0;

    while (i < MAXLEN && (c = getchar()) != '\n' && c != EOF)
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int str_end(char *s, char *t){
    if (len2 > len1) {
        printf("error: the second string should be smaller");
        return -1;
    }

    for (int i = len1 - len2, j = 0; i < len1; i++, j++) {
        if (s[i] != t[j])
            return 0;
    }
    return 1;

