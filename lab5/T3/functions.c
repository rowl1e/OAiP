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

void print_array(int** array, int* length, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length[i]; j++)
            printf("%5d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

//Mem allocation
/*==========================================================================*/
int* cc_1D (int size) {
    int* array = (int*) calloc (size, sizeof(int));
    return array;
}

int** cc_2D (int* length, int height) {
    int** array = (int**) calloc (height, sizeof(int*));
    for (int i = 0; i < height; i++)
        array[i] = (int*) calloc (length[i], sizeof(int));
    return array;
}

void memory_freeing (int** array, int height) {
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}

//Filling Array
/*==========================================================================*/
void choice_of_two (int* choice) {
    while (!scanf("%d", choice) || (*choice) != 1 && (*choice) != 2 || getchar() != '\n') {
        error();
        rewind(stdin);
    }
}

//Keyboard input
void input_array_elements (int** array, int* length, int height) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length[i] - 1; j++)
            array[i][j] = getint();
}

//Random input
int rn (int limit) {
    return (rand() %  (2 * limit)) - limit;
}

void random_numbers (int **array, int* length, int height) {
    srand(time(NULL));
    int limit = getint_min(1);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length[i] - 1; j++)
            array[i][j] = rn(limit);
}

//Task functions
/*======================================================================*/
void element_swap (int** array, int* length, int i, int j) {
        for (; j < length[i] - 1; j++) {
            int temp = array[i][j + 1];
            array[i][j + 1] = array[i][j];
            array[i][j] = temp;
        }
}

void task3 (int** array, int* length, int height, int k) {
    int flag = 0;
    int temp_length = 0;
    for (int i = 0; i < height; i++)
        for (int j = 1; j < length[i] - 1; j++)
            if (array[i][j] > k) {
                temp_length = length[i];
                for (int m = j + 1; m < length[i] - 1; m++)
                    if (array[i][j] == array[i][m]){
                        element_swap(array, length, i, m);
                        length[i]--;
                        flag = 1;
                    }
                if (temp_length > length[i])
                    j--;
            }
    if(flag != 0)
        for(int i = 0; i < height; i++)
            array[i] = (int*) realloc (array[i], length[i] * sizeof(int));
}

//Other
/*======================================================================*/
void array_filling (int** array, int *length, int height) {
    int choice;
    printf("\nChoose: keyboard input(1) or random input(2):\n");
    choice_of_two(&choice);
    switch (choice) {
        case 1:
            printf("\nEnter array elements:\n");
            input_array_elements(array, length, height);
            break;
        case 2:
            printf("\nEnter limit of random numbers of array:\n");
            random_numbers(array, length, height);
    }
    printf("\n\033[1;34mYour array is:\033[0m\n\n");
    print_array(array, length, height);
}
/*==========================================================================*/