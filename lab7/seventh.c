#include <stdio.h> 
#include <stdlib.h>
#include "functions.h"
#include "strg.h"

void T1 ();
void T2 ();

int main () {
    void (*task[])() = {T1, T2};
    while (1) {
        printf("Choose task:\n\tTask1 - 1\n\tTask2 - 2\n\tClose programm - 0\n\n");
        int choice = getint_minmax(0, 2);
        if (choice == 0){
            printf("The program has ended\n");   
            system("pause");
            return 0;
        }
        else {
            task[choice - 1]();
            printf("\n");
        }
    }
}

void T1 () {
    printf("\nEnter string:\n");
    char* str = get_str();
    int length = str_len(str);
    int word_with_even_number_of_letters = 0;
    // cowaenof - Count Of Words With An Even Number Of Letters
    cowaenof(str, length, &word_with_even_number_of_letters);
    printf("\n\033[1;32mCount of words with even number of letters is \033[1;34m%d\033[0m\n", word_with_even_number_of_letters);
    free(str);
}

void T2 () {
    int pos_start = -1;
    printf("\nEnter string S2:\n");
    char* str2 = get_str();
    int length2 = str_len(str2);
    printf("\nS2 length is %d\n", length2);

    printf("\nEnter string S1:\n");
    char* str1 = get_str();
    int length1 = str_len(str1);
    printf("\nS1 length is %d\n", length1);

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


/*Even S1 in S2*/
//plen - sizeof pos_start and pos_end arrays

// void T2 () {
//     int plen = 0;
//     int* pos_start = malloc(1 * sizeof(int));
//     printf("\nEnter string S2:\n");
//     char* str2 = get_str();
//     int length2 = str_len(str2);
//     printf("\nS2 length is %d\n", length2);

//     printf("\nEnter string S1:\n");
//     char* str1 = get_str();
//     int length1 = str_len(str1);
//     printf("\nS1 length is %d\n", length1);

//     s1_pos_in_s2_2(str1, str2, pos_start, &plen);

//     int* pos_end = malloc (plen * sizeof(int));
//     for (int i = 0; i < plen; i++)
//         pos_end[i] = pos_start[i] + length1;
    
//     printf("\n\n\033[1;32mResult:\033[0m\n");
//     for (int i = 0; i < plen; i++) {
//         if (pos_start[i] != -1)
//             printf("\tRange [%d; %d]\n", pos_start[i] + 1, pos_end[i]);
//         else
//             printf("\t-1\n");
//     }
//     free(str1);
//     free(str2);
//     free(pos_start);
//     free(pos_end);
// }