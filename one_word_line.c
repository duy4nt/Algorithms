#include <stdio.h>

main() {
    int c, state;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {

            printf("%c", c);

            if (c == ' ') {
                printf("\n");
            }
        }
    }
}
