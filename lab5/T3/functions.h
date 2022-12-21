#pragma once
#include "functions.c"

void error();
int getint();
int getintmin(int min);
void outputArray(int** array, int* length, int height);
int* cc1(int size);
int** cc2(int* length, int height);
void memoryFreeing(int** array, int height);
void inputChoice(int* inputChoice);
void inputArrayElements(int** array, int* length, int height);
int rn(int limit);
void randomNumbers(int **array, int* length, int height);
void elementSwap(int** array, int* length, int i, int j);
void task3(int** array, int* length, int height, int k);