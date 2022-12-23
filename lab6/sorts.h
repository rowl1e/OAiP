#pragma once
#include "sorts.c"

void mergeSort_MOD (int** array, int start, int end);
void merge_MOD (int** array, int start, int end, int mid);

void bubleSort_MOD (int **array, int length);
int sum_elements_of_row (int** array, int length, int i); // For Buble Sort Row
void bubleSort_Rows (int** array, int length, int height);

void Reverse_MOD (int** array, int length);