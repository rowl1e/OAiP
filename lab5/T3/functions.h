#pragma once
#include "functions.c"

void error();
int getint();
int getint_min (int min);
void print_array(int** array, int* length, int height);

int* cc_1D (int size);
int** cc_2D (int* length, int height);
void memory_freeing (int** array, int height);

void choice_of_two (int* choice);
void input_array_elements (int** array, int* length, int height);
int rn(int limit);
void random_numbers (int **array, int* length, int height);

void element_swap (int** array, int* length, int i, int j);
void task3 (int** array, int* length, int height, int k);

void array_filling (int** array, int *length, int height);