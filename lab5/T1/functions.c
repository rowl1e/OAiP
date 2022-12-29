#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Text functions
void error () {
    printf("\033[1;31mInvalid input. Try again:\033[0m\n");
}

//IO functions
/*==========================================================================*/
int getint () {
    int integer;
    while (!scanf("%d", &integer) || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}

int getint_min (int min) {
    int integer;
    while (!scanf("%d", &integer) || integer < min || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}

void print_array (int *array, int size) {
    printf("\n");
    for (int i = 0; i < size; i++)
            printf("%5d ", array[i]);
    printf("\n\n");
}

//Task functions
/*======================================================================*/
void bubleSort (int* array, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = (size - 1); j > i; j--)
            if (array[j] > array[j - 1]) {
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
}

void duplicate_number_remover (int *array, int *n) {
    for (int i = 0; i < (*n); i++)
        for (int j = i + 1; j < (*n); j++)
            if (array[i] == array[j]) {
                for (int k = j; k < (*n) - 1; k++)
                    array[k] = array[k+1];
                (*n)--;
            }
}

void task1 (int *array1, int *array2, int* size1, int size2) {
    for (int i = 0; i < size2; i++)
        for (int j = 0; j < (*size1); j++) {
            if (array2[i] == array1[j]) {
                for (int k = j; k < (*size1) - 1; k++) {
                    int tmp = array1[k + 1];
                    array1[k + 1] = array1[k];
                    array1[k] = tmp;
                }
                (*size1)--;
                array1 = (int*) realloc (array1, (*size1) * sizeof(int));
            }
            if ((*size1) == 1 && array2[i] == array1[0])
                (*size1) = 0;  
        }
}

/*======================================================================*/
void input_sizes_of_arrays (int *size1, int *size2) {
    printf("\nInput the size of array1:\n");
    *size1 = getint_min(1);
    printf("\nInput the size of array2:\n");
    *size2 = getint_min(1);
}

void input_array_elements (int *array1, int *array2, int size1, int size2) {
    printf("\nInput array1 elements:\n");
    for (int i = 0; i < size1; i++)
        array1[i] = getint();
    printf("\nInput array2 elements:\n");
    for (int i = 0; i < size2; i++)
        array2[i] = getint();
}

void result (int *array, int size) {
    printf("\n\033[1;32mResult:\033[0m\n");
    if (size == 0)
        printf("\t\033[1;34mYour array is gone...\033[0m\n\n");
    else
        print_array(array, size);
}

void print_arrays (int* array1, int* array2, int size1, int size2) {
    printf("\n======================\n");
    for (int i = 0; i < size1; i++)
            printf("%5d ", array1[i]);
    printf("\n======================\n");
    for (int i = 0; i < size2; i++)
            printf("%5d ", array2[i]);
    printf("\n======================\n");
}
/*==========================================================================*/