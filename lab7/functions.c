#include <stdio.h>
#include "strg.h"

//Text functions
void error () {
    printf("\033[1;31mInvalid input. Try again:\033[0m\n");
}

//Getint functions
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

// cowaenof - Count Of Words With An Even Number Of Letters
void cowaenof (char* str, int length, int* word_with_even_number_of_letters) {
    int count = 0; 
    for (int i = 0; i < length; i++) {
        if (isletter_(str[i])){
            count++;
            if (isletter_(str[i + 1]) != 1) {
                if (count % 2 == 0)
                    (*word_with_even_number_of_letters)++;
                count = 0;
            }
        }
    }
}

void s1_pos_in_s2 (char* str1, char* str2, int* pos_start) {
    int i = 0;
    int k = 0;
    int len1 = str_len(str1);
    while (str2[i] != '\0') {
        int letter_place = len1 - 1 - k;
        if (str2[i] == str1[k] && str2[i - k + letter_place] == str1[letter_place] && k < (len1 / 2)) {
            if (k == 0)
                (*pos_start) = i;
            ++k;
            ++i;
        }
        else {
            k = 0;
            (*pos_start) == -1;
            ++i;
        }
    }
}