#include <stdio.h> 

#define MAXLEN 1000

int get_str(char *str);
int cmp(char *str_one, char *str_two);

main() {
    int len;
    int res;
    
    char str_one[MAXLEN];
    char str_two[MAXLEN];

    get_char(str_one);
    get_char(str_two)
    
    res = cmp(str_one, str_two);

    if (res == 0)
        printf("the strinf are equal");
    else if (res < 0)
        printf("the second string is more lexically equal");
    else
        printf("the first string is more lexically equal");
        
}

int get_str(char *s) {
    int i, c;
    i = 0;

    while (i < MAXLEN && (c = getchar()) != '\n' && c != EOF)
        s[i++] = c;

    s[i] = '\0';
    
    return i; 
}

int cmp(char *s, char *t) {
    while (*s == *t) {
        if *s == '\0' {
            return 0;
        }
        s++;
        t++;
    }

    return *s - *t;    
}
