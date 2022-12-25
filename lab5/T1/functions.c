#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Text functions
void error(){
    printf("\033[1;31mInvalid input. Try again:\033[0m\n");
}

//IO functions
int getint(){
    int x;
    while (!scanf("%d", &x) || getchar() != '\n'){
            error();
            rewind(stdin);
    }
    return x;
}

int getintmin(int min){
    int x;
    while (!scanf("%d", &x) || x < min || getchar() != '\n'){
            error();
            rewind(stdin);
    }
    return x;
}

void outputArray(int *array, int size){
    printf("\n");
    for(int i = 0; i < size; i++)
            printf("%5d ", array[i]);
    printf("\n\n");
}

//Task functions
void bubleSort(int arraySize, int *array){
    for(int i = 0; i < arraySize - 1; i++)
        for(int j = (arraySize - 1); j > i; j--)
            if(array[j] > array[j - 1]){
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
}

void duplicateNumberRemover(int *array, int *n){
    for(int i = 0; i < (*n); i++)
        for(int j = i + 1; j < (*n); j++)
            if(array[i] == array[j]) {
                for(int k = j; k < (*n) - 1; k++)
                    array[k] = array[k+1];
                (*n)--;
            }
}

void task1(int *array1, int *array2, int* size1, int size2){
    for(int i = 0; i < size2; i++)
        for(int j = 0; j < (*size1); j++){
            if(array2[i] == array1[j]) {
                for(int k = j; k < (*size1) - 1; k++){
                    int tmp = array1[k + 1];
                    array1[k + 1] = array1[k];
                    array1[k] = tmp;
                }
                (*size1)--;
                array1 = (int*) realloc (array1, (*size1) * sizeof(int));
            }
            if((*size1) == 1 && array2[i] == array1[0])
                (*size1) = 0;  
        }
}