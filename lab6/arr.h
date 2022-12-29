#pragma once
#include "arr.c"

void error ();
int getint ();
int getint_min (int min);
int getint_minmax (int min, int max);
void print_array_1D (int* array, int length);
void print_array_2D (int** array, int length, int height);

int* mc_1D (int length);
int** mc_2D (int length, int height);
void memory_freeing_2D (int** array, int height);

void input_array_elements_1D (int* array, int length);
void input_array_elements_2D (int** array, int length, int height);
int rn (int limit);
void random_numbers_1D (int* array, int length);
void random_numbers_2D (int **array, int length, int height);

void copy_array1_to_array2 (int* array, int* array_duplicate, int length);
int even_count (int* array, int length);
void even_filling (int* array, int length, int** even, int even_length);
void array_edit (int* array, int length, int** even, int count);

void sum_print (int** array, int length, int height);

void array_filling (int** array2, int* array1, int length, int height, int task);
void time_result (clock_t time_start, clock_t time_end, int method);