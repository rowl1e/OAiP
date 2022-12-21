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

void outputArray(int** array, int* length, int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < length[i]; j++)
            printf("%5d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

//Mem allocation
int* cc1(int size){
    int* array = (int*) calloc (size, sizeof(int));
    return array;
}

int** cc2(int* length, int height){
    int** array = (int**) calloc (height, sizeof(int*));
    for(int i = 0; i < height; i++)
        array[i] = (int*) calloc (length[i], sizeof(int));
    return array;
}

void memoryFreeing(int** array, int height){
    for(int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}

//Filling Array
void inputChoice(int* inputChoice){
    while (!scanf("%d", inputChoice) || (*inputChoice) != 1 && (*inputChoice) != 2 || getchar() != '\n'){
        error();
        rewind(stdin);
    }
}

//Keyboard input
void inputArrayElements(int** array, int* length, int height){
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length[i] - 1; j++)
            array[i][j] = getint();
}

//Random input
int rn(int limit){
    return (rand() %  (2 * limit)) - limit;
}

void randomNumbers(int **array, int* length, int height){
    srand(time(NULL));
    int limit = getintmin(1);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length[i] - 1; j++)
            array[i][j] = rn(limit);
}

//Task functions
void elementSwap(int** array, int* length, int i, int j){
        for(; j < length[i] - 1; j++){
            int temp = array[i][j + 1];
            array[i][j + 1] = array[i][j];
            array[i][j] = temp;
        }
}

void task3(int** array, int* length, int height, int k){
    int flag = 0;
    for(int i = 0; i < height; i++)
        for(int j = 1; j < length[i] - 1; j++)
            if(array[i][j] > k){
                elementSwap(array, length, i, j);
                length[i]--;
                j--;
                flag++;
            }
    if(flag != 0)
        for(int i = 0; i < height; i++)
            array[i] = (int*) realloc (array[i], length[i] * sizeof(int));
}