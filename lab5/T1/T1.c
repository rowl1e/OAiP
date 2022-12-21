#include "functions.h"

void inputSizesOfArrays(int *size1, int *size2) {
    printf("\nInput the size of array1:\n");
    *size1 = getintmin(1);
    printf("\nInput the size of array2:\n");
    *size2 = getintmin(1);
}

void inputAE(int *array1, int *array2, int size1, int size2) {
    printf("\nInput array1 elements:\n");
    for(int i = 0; i < size1; i++)
        array1[i] = getint();
    printf("\nInput array2 elements:\n");
    for(int i = 0; i < size2; i++)
        array2[i] = getint();
}

void result(int *array, int size){
    printf("\n\033[1;32mResult:\033[0m\n");
    if(size == 0)
        printf("\t\033[1;34mYour array is gone...\033[0m\n\n");
    else
        outputArray(array, size);
}

void T1(){
    int *array1, *array2, size1, size2;
    inputSizesOfArrays(&size1, &size2);
    array1 = malloc (size1 * sizeof(int));
    array2 = malloc (size2 * sizeof(int));
    inputAE(array1, array2, size1, size2);
    bubleSort(size2, array2);
    duplicateNumberRemover(array2, &size2);
    task1(array1, array2, &size1, size2);
    result(array1, size1);
    free(array1);
    free(array2);
}

int main(){
    T1();
    system("pause");
    return 0;
}