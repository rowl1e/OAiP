#pragma once
#include "functions.c"

void error ();
int getint ();
int getint_min (int min);
int getint_minmax (int min, int max);

void cowaenof (char* str, int length, int* word_with_even_number_of_letters);
void s1_pos_in_s2 (char* str1, char* str2, int* pos_start);