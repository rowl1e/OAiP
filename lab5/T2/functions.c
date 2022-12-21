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

void outputArray(int** array, int length, int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < length; j++)
            printf("%5d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

//Mem allocation
int** mc(int length, int height){
    int** array = (int**) malloc (height * sizeof(int*));
    for(int i = 0; i < height; i++)
        array[i]= (int*) malloc (length * sizeof(int));
    return array;
}

int** cc(int length, int height){
    int** array = (int**) calloc (height, sizeof(int*));
    for(int i = 0; i < height; i++)
        array[i]= (int*) calloc (length, sizeof(int));
    return array;
}

void memoryFreeing(int** array, int height){
    for(int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}

//Filling Array
void inputChoice(int* choice){
    while (!scanf("%d", choice) || (*choice) != 1 && (*choice) != 2 || getchar() != '\n'){
        error();
        rewind(stdin);
    }
}

//Keyboard input  
void inputArrayElements(int** array, int length, int height){
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length; j++)
            array[i][j] = getint();
}

//Random input
int rn(int limit){
    return (rand() %  (2 * limit)) - limit;
}

void randomNumbers(int **array, int length, int height){
    srand(time(NULL));
    int limit = getintmin(1);
    for(int i = 0; i < height; i++)
        for(int j = 0; j < length; j++)
            array[i][j] = rn(limit);
}

//Task Functions
void columnSwaper(int** array, int length, int height, int lengthptr){
    for(int i = 0; i < height; i++)
        for(int j = lengthptr; j < length - 1; j++){
            int temp = array[i][j + 1];
            array[i][j + 1] = array[i][j];
            array[i][j] = temp;
        }
}

void columnRemover(int** array, int* length, int height){
    for(int i = 0; i < (*length); i++)
        for(int j = 0; j < height - 1; j++)
            if(array[j][i] == 0 && array[j + 1][i] == 0){
                    columnSwaper(array, (*length), height, i);
                    (*length)--;
                    i--;
                    break;
                }
    array = (int**) realloc (array, (*length) * sizeof(int*));
}