#pragma once
#include "sorts.c"

void mergeSort_MOD (int** array, int start, int end);
void merge_MOD (int** array, int start, int end, int mid);

void bubleSort_MOD (int **array, int length);

int sum_of_row_elements (int** array, int length, int i);
void bubleSort_rows (int** array, int length, int height);

void reverse_MOD (int** array, int length);