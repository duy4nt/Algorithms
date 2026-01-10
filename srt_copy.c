#include <stdio.h>

#define MAXLEN 1000

int get_str(char *str);
void str_copy(char *souce, char *destination);

main() {
    int len;
    
    char str[MAXLEN];
    
    len = get_str(str);

    char cstr[len];
    
    str_copy(srt, cstr);
}

void str_copy(char *s, char *t) {
    int i;
    i = 0;
    
    while (s[i] = t[i] != '\0')
        i++;
}

/*

void str_copy(char *s, char *t) {
    while ((*s++ = *t++) != '\0') ;
}

*/

int get_str(char s*) {
    int i, c;
    i = 0;

    while (i < MAXLEN && (c = getchar()) != '\n' && c != EOF)
        s[i++] = c;
        
    s[i] = '\0';
    
    return i;
}
