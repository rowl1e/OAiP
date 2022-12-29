#pragma once
#include "functions.c"

void error ();
int getint ();
int getint_min (int min);
int getint_minmax (int min, int max);

void mergeSort (int** array, char*** strs, int start, int end);
void merge (int** array, char*** strs, int start, int end, int mid);

int shortest_word_size (char** str);
void copy_argv_to_strs (int argc, char** argv, char** strs, int* sizes);