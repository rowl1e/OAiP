#include <stdio.h>

void error () {
    printf("\033[1;31mInvalid input. Try again:\033[0m\n");
}

//getint functions
int getint () {
    int integer;
    while (!scanf("%d", &integer) || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}

int getint_min (int min) {
    int integer;
    while (!scanf("%d", &integer) || integer < min || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}

int getint_minmax (int min, int max) {
    int integer;
    while (!scanf("%d", &integer) || integer < min || integer > max || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}