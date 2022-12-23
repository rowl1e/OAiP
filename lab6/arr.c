#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//IO functions
void outputArray_1D (int* array, int length) {
    for (int i = 0; i < length; i++)
        printf("%5d ", array[i]);
    printf("\n\n");
}

void outputArray_2D (int** array, int length, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++)
            printf("%5d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

//Mem allocation
int* mc_1D (int length) {
    return (int*) malloc (length * sizeof(int));
}

int** mc_2D (int length, int height) {
    int** array = (int**) malloc (height * sizeof(int*));
    for (int i = 0; i < height; i++)
        array[i] = (int*) malloc (length * sizeof(int));
    return array;
}

void memoryFreeing_2D (int** array, int height) {
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}

//Keyboard input
void inputArrayElements_1D (int* array, int length) {
    for (int i = 0; i < length; i++)
            array[i] = getint();
}

void inputArrayElements_2D (int** array, int length, int height) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length - 1; j++)
            array[i][j] = getint();
}

//Random input
int rn (int limit) {
    return (rand() %  (2 * limit)) - limit;
}

void randomNumbers_1D (int* array, int length) {
    srand(time(NULL));
    int limit = getint_min(1);
    for (int i = 0; i < length; i++)
            array[i] = rn(limit);
}

void randomNumbers_2D (int **array, int length, int height) {
    srand(time(NULL));
    int limit = getint_min(1);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++)
            array[i][j] = rn(limit);
}

//Other Functions
//T1
void copy (int* array, int* array_duplicate, int length) {
    for (int i = 0; i < length; i++)
        array_duplicate[i] = array[i];
}

void evenSize (int* array, int length, int* count) {
    for (int i = 0; i < length; i++)
        if (array[i] % 2 == 0)
            (*count)++;
}

void evenArrayFilling (int* array, int length, int** even, int count) {
    int c = 0;
    for (int i = 0; i < length; i++)
        if (array[i] % 2 == 0){
            even[0][c] = array[i];
            even[1][c] = i;
            c++;
        }
}

void arrayEdit (int* array, int length, int** even, int count) {
    int c = 0;
    for (int i = 0; i < length; i++){
        if (c == count) break;
        if (i == even[1][c]){
            array[i] = even[0][c];
            c++;
        }
    }
}

//T2
void sum_output (int** array, int length, int height) {
    for (int i = 0; i < height; i = i + 2) {
        printf("\tSum row[%d] is %d\n", i + 1, sum_elements_of_row(array, length, i));
    }
}

//Array filling
void choice_of_two (int* choice) {
    while (!scanf("%d", choice) || (*choice) != 1 && (*choice) != 2 || getchar() != '\n') {
        error();
        rewind(stdin);
    }
}

void arrayFilling (int** array2, int* array1, int length, int height, int task) {
    int choice;
    printf("\nChoose type of input: \n\tkeyboard(1) or random(2):\n");
    choice_of_two(&choice);
    switch (choice) {
        case 1:
            printf("\nEnter array elements:\n");
            if (task == 1) inputArrayElements_1D(array1, length);
            else inputArrayElements_2D(array2, length, height);
            break;
        case 2:
            printf("\nEnter limit of random numbers of array:\n");
            if (task == 1) randomNumbers_1D(array1, length);
            else randomNumbers_2D(array2, length, height);
    }
    printf("\n\033[1;34mYour array is:\033[0m\n\n");
    if (task == 1) outputArray_1D(array1, length);
    else outputArray_2D(array2, length, height);
}