#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Text functions
void error () {
    printf("\033[1;31mInvalid input. Try again:\033[0m\n");
}

//getint functions
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

void print_array (int** array, int length, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++)
            printf("%5d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

//Mem allocation
/*==========================================================================*/
int** mc (int length, int height) {
    int** array = (int**) malloc (height * sizeof(int*));
    for (int i = 0; i < height; i++)
        array[i]= (int*) malloc (length * sizeof(int));
    return array;
}

int** cc (int length, int height) {
    int** array = (int**) calloc (height, sizeof(int*));
    for (int i = 0; i < height; i++)
        array[i]= (int*) calloc (length, sizeof(int));
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
void input_array_elements (int** array, int length, int height) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++)
            array[i][j] = getint();
}

//Random input
int rn (int limit) {
    return (rand() %  (2 * limit)) - limit;
}

void random_numbers (int **array, int length, int height) {
    srand(time(NULL));
    int limit = getint_min(1);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++)
            array[i][j] = rn(limit);
}

//Task Functions
/*======================================================================*/
void column_swap (int** array, int length, int height, int column_place) {
    for (int i = 0; i < height; i++)
        for (int j = column_place; j < length - 1; j++) {
            int temp = array[i][j + 1];
            array[i][j + 1] = array[i][j];
            array[i][j] = temp;
        }
}

void column_remover (int** array, int* length, int height) {
    for (int i = 0; i < (*length); i++)
        for (int j = 0; j < height - 1; j++)
            if (array[j][i] == 0 && array[j + 1][i] == 0) {
                    column_swap(array, (*length), height, i);
                    (*length)--;
                    i--;
                    break;
                }
    array = (int**) realloc (array, (*length) * sizeof(int*));
}

/*======================================================================*/
void input_sizes_of_arrays (int* length, int* height) {
    printf("\nInput the size of rows:\n");
    *length = getint_min(1);
    printf("\nInput the size of cols:\n");
    *height = getint_min(1);
}

void array_filling (int** array, int length, int height) {
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
    printf("\n\033[1;32mYour array is:\033[0m\n\n");
    print_array(array, length, height);
}

void result (int** array, int length, int height) {
    if (length != 0) {
        printf("\033[1;34mYour edited array is:\033[0m\n\n");
        print_array(array, length, height);
    }
    else printf("\033[1;34mYour array is gone...\033[0m\n\n");
}
/*==========================================================================*/