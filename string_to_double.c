#include <stdio.h>
#include <stdbool.h>
#define MAXLINE 1000

int atof(char line[]) ;
int getlined(char line[], int maxlimit) ;
bool isdigited(int character) ;
bool isspaced(int character) ;

main() {
    char snum[MAXLINE];
    double dnum; int index;

    index = getlined(snum, MAXLINE);
    dnum = atof(snum);

    printf("%.2f\n", dnum);
}

int atof(char s[]) {
    int i, sign;
    double val, power;

    for (i = 0; isspaced(s[i]); i++) ;
    sign = (s[i] == '-')? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigited(s[i]); i++) {
        val = val * 10.0 + s[i] - '0';
    }
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigited(s[i]); i++) {
        val = val * 10.0 + s[i] - '0';
        power *= 10.0;
    }
    return (sign * val / power);
}

int getlined(char l[], int limit) {
    int i, c;
    i = 0;

    while((c = getchar()) != EOF && c != '\n') {
        l[i++] = c;
    }

    return i;
}

bool isspaced(int c) {
    if (c == ' ' || c == '\b' || c == '\t')
        return true;
    else
        return false;
}

bool isdigited(int c) {
    if (c <= '9' && c >= '0')
        return true;
    else
        return false;
}
