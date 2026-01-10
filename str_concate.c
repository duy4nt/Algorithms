#include <stdio.h>

#define MAXLEN 1000

void str_concat(char *to, char *from);
int get_str(char str);

main() {
    int len_to, len_from;

    char str_to[MAXLEN];
    char str_from[MAXLEN];

    
}

int get_str(char *s) {
    int i, c;
    i = 0;

    while (i < MAXLEN && (c = getchar()) != '\n' && c != EOF) 
        s[i++] = c;
    
    s[i] = '\0';

    return i;
}


/*

void str_concat(char *s, char *t) {
    while (*s != '\0') *s++;
    while ((*s++ = *t++) != '\0')
}

*/

void str_concat(char *s, char *t) {
    int i, j;
    i = j = 0;

    while (s[i] != '\0') 
        i++;

    while (t[j] != '\0' && (i + j) < MAXLEN)
        s[i++] = t[j++];
}
