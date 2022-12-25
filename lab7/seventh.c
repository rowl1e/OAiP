#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "getint.h"
#include "functions.h"
#include "strg.h"

void T1 ();
void T2 ();

int main (int task) {
    printf("Choose task:\n\tTask1 - 1\n\tTask2 - 2\n\n");
    choice_of_two(&task);
    switch (task) {
        case 1:
            T1();
            break;
        case 2:
            T2();
    }
    system("pause");
    return 0;
}

void T1 () {
    printf("\nEnter string:\n");
    char* str = get_str();
    int length = str_len(str);
    int word_with_even_number_of_letters = 0;
    // cowaenof - Count Of Words With An Even Number Of Letters
    cowaenof(str, length, &word_with_even_number_of_letters);
    printf("\n\033[1;32mCount of words with even number of letters is %d\033[0m\n", word_with_even_number_of_letters);
    free(str);
}

void T2 () {
    int pos_start = -1;
    printf("\nEnter string S2:\n");
    char* str2 = get_str();
    int length2 = str_len(str2);
    printf("\nEnter string S1:\n");
    char* str1 = get_str();
    int length1 = str_len(str1);
    s1_pos_in_s2(str1, str2, &pos_start);
    int pos_end = pos_start + length1;
    printf("\n\n\033[1;32mResult:\033[0m\n");
    if (pos_start != -1)
        printf("\tRange [%d; %d]\n", pos_start + 1, pos_end);
    else
        printf("\t-1\n");
    free(str1);
    free(str2);
}