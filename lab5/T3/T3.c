#include "functions.h"

void arrayFilling(int** array, int *length, int height){
    int choice;
    printf("\nChoose: keyboard input(1) or random input(2):\n");
    inputChoice(&choice);
    switch(choice){
        case 1:
            printf("\nEnter array elements:\n");
            inputArrayElements(array, length, height);
            break;
        case 2:
            printf("\nEnter limit of random numbers of array:\n");
            randomNumbers(array, length, height);
    }
    printf("\n\033[1;34mYour array is:\033[0m\n\n");
    outputArray(array, length, height);
}

void T3(){
    printf("\nEnter height of cols:\n");
    int height = getintmin(1);
    int* length = cc1(height);

    printf("\nEnter sizes of rows:\n");
    for(int i = 0; i < height; i++)
        length[i] = getintmin(1) + 1;
    int** array = cc2(length, height);
    arrayFilling(array, length, height);

    printf("\nEnter k:\n");
    int k = getint();
    task3(array, length, height, k);

    printf("\n\033[1;32mYour edited array is:\033[0m\n\n");
    outputArray(array, length, height);
    memoryFreeing(array, height);
    free(length);
}

int main(){
    T3();
    system("pause");
    return 0;
}