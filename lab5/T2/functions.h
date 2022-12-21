#pragma once
#include "functions.c"

void error();
int getint();
int getintmin(int min);
void outputArray(int** array, int length, int height);
int** mc(int length, int height);
int** cc(int length, int height);
void memoryFreeing(int** array, int height);
void inputChoice(int* inputChoice);
void inputArrayElements(int** array, int length, int height);
int rn(int limit);
void randomNumbers(int **array, int length, int height);
void columnSwaper(int** array, int length, int height, int lengthptr);
void columnRemover(int** array, int* length, int height);