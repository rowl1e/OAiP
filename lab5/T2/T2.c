#include "functions.h"

void inputSizesOfArrays(int* length, int* height){
    printf("\nInput the size of rows:\n");
    *length = getintmin(1);
    printf("\nInput the size of cols:\n");
    *height = getintmin(1);
}

void arrayFilling(int** array, int length, int height){
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
    printf("\n\033[1;32mYour array is:\033[0m\n\n");
    outputArray(array, length, height);
}

void result(int** array, int length, int height){
    if(length != 0){
        printf("\033[1;34mYour edited array is:\033[0m\n\n");
        outputArray(array, length, height);
    }
    else printf("\033[1;34mYour array is gone...\033[0m\n\n");
}

void T2(){
    int length, height;
    inputSizesOfArrays(&length, &height);
    int** array = cc(length, height);
    arrayFilling(array, length, height);
    columnRemover(array, &length, height);
    result(array, length, height);
    memoryFreeing(array, length);
}

int main(){
    T2();
    system("pause");
    return 0;
}