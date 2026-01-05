#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXLINE 1000

int sp = 0;
double val[MAXVAL];

int getop(char []);
void push(double) ;
double pop(void);
double atof(char s[]);
int getch(void);
void ungetch(void);

main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '*':
                push(pop() * pop());
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Divide by zero error");
                break;

            case '\n':
                printf("\t%.8g\n", pop());
                break;

            default:
                printf("Unknown command");
                break;
        }
    }

    return 0;
}

int gettop()

double atof(char s[]) {
    int i, sign;
    double val, power;

    for (i = 0; isspace(s[i]); i++) ;
    sign = if (s[i] == '-')? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power = power * 10.0;
    }

    return (sign * val / power);
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Stack full");
}

double pop() {
    if (sp > 0)
        return val[--sp];
    else
        prinf("Stack empty");
        return 0.0;
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



