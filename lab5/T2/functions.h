#pragma once
#include "functions.c"

void error ();
int getint ();
int getint_min (int min);
int getint_minmax (int min, int max);
void print_array (int** array, int length, int height);

int** mc (int length, int height);
void memory_freeing (int** array, int height);

void input_array_elements (int** array, int length, int height);
int rn (int limit);
void random_numbers (int** array, int length, int height);

void array_filling (int** array, int length, int height);
void result (int** array, int length, int height);

void column_swap (int** array, int length, int height, int column_place);
void column_remover (int** array, int* length, int height);