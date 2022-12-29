#pragma once
#include "functions.c"

void error ();
int getint ();
int getint_min (int min);
void print_array (int *array, int size);

void bubleSort (int* array, int size);
void duplicate_number_remover (int *array, int *n);
void task1 (int *array1, int *array2, int* size1, int size2);

void input_sizes_of_arrays (int *size1, int *size2);
void input_array_elements (int *array1, int *array2, int size1, int size2);
void result (int *array, int size);
void print_arrays (int* array1, int* array2, int size1, int size2);