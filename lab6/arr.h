#pragma once
#include "arr.c"

void outputArray_1D (int* array, int length);
void outputArray_2D (int** array, int length, int height);

int* mc_1D (int length);
int** mc_2D (int length, int height);
void memoryFreeing_2D (int** array, int height);

void inputArrayElements_1D (int* array, int length);
void inputArrayElements_2D (int** array, int length, int height);
int rn (int limit);
void randomNumbers_1D (int* array, int length);
void randomNumbers_2D (int **array, int length, int height);

void copy (int* array, int* array_duplicate, int length);
void evenSize (int* array, int length, int* count);
void evenArrayFilling (int* array, int length, int** even, int count);
void arrayEdit (int* array, int length, int** even, int count);

void sum_output (int** array, int length, int height);

void choice_of_two (int* choice);
void arrayFilling (int** array2, int* array1, int length, int height, int task);