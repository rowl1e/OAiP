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

int getint_minmax (int min, int max) {
    int integer;
    while (!scanf("%d", &integer) || integer < min || integer > max || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}

void print_array_1D (int* array, int length) {
    for (int i = 0; i < length; i++)
        printf("%5d ", array[i]);
    printf("\n\n");
}

void print_array_2D (int** array, int length, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++)
            printf("%5d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

//Mem allocation
/*==========================================================================*/
int* mc_1D (int length) {
    return (int*) malloc (length * sizeof(int));
}

int** mc_2D (int length, int height) {
    int** array = (int**) malloc (height * sizeof(int*));
    for (int i = 0; i < height; i++)
        array[i] = (int*) malloc (length * sizeof(int));
    return array;
}

void memory_freeing_2D (int** array, int height) {
    for (int i = 0; i < height; i++)
        free(array[i]);
    free(array);
}

//Array filling
/*==========================================================================*/

//Keyboard input
void input_array_elements_1D (int* array, int length) {
    for (int i = 0; i < length; i++)
            array[i] = getint();
}

void input_array_elements_2D (int** array, int length, int height) {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length - 1; j++)
            array[i][j] = getint();
}

//Random input
int rn (int limit) {
    return (rand() %  (2 * limit)) - limit;
}

void random_numbers_1D (int* array, int length) {
    srand(time(NULL));
    int limit = getint_min(1);
    for (int i = 0; i < length; i++)
            array[i] = rn(limit);
}

void random_numbers_2D (int** array, int length, int height) {
    srand(time(NULL));
    int limit = getint_min(1);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < length; j++)
            array[i][j] = rn(limit);
}

//T1
/*==========================================================================*/
void copy_array1_to_array2 (int* array, int* array_duplicate, int length) {
    for (int i = 0; i < length; i++)
        array_duplicate[i] = array[i];
}

int even_count (int* array, int length) {
    int count_of_even_numbers = 0;
    for (int i = 0; i < length; i++)
        if (array[i] % 2 == 0)
            count_of_even_numbers++;
    return count_of_even_numbers;
}

void even_filling (int* array, int length, int** even, int even_length) {
    int c = 0;
    for (int i = 0; i < length; i++)
        if (array[i] % 2 == 0 && c < even_length){
            even[0][c] = array[i];
            even[1][c] = i;
            c++;
        }
}

void array_edit (int* array, int length, int** even, int even_length) {
    int c = 0;
    for (int i = 0; i < length; i++){
        if (c == even_length) break;
        if (i == even[1][c]){
            array[i] = even[0][c];
            c++;
        }
    }
}

//T2
/*==========================================================================*/
void sum_print (int** array, int length, int height) {
    for (int i = 0; i < height; i = i + 2)
        printf("\tSum row[%d] is %d\n", i + 1, sum_of_row_elements(array, length, i));
}

//Other
/*==========================================================================*/
void array_filling (int** array2, int* array1, int length, int height, int task) {
    printf("\nChoose type of input: \n\tkeyboard(1) or random(2):\n");
    int choice = getint_minmax(1, 2);
    switch (choice) {
        case 1:
            printf("\nEnter array elements:\n");
            if (task == 1) input_array_elements_1D(array1, length);
            else input_array_elements_2D(array2, length, height);
            break;
        case 2:
            printf("\nEnter limit of random numbers of array:\n");
            if (task == 1) random_numbers_1D(array1, length);
            else random_numbers_2D(array2, length, height);
    }
    printf("\n\033[1;34mYour array is:\033[0m\n\n");
    if (task == 1) print_array_1D(array1, length);
    else print_array_2D(array2, length, height);
}

void time_result (clock_t time_start, clock_t time_end, int method) {
    if(method == 1) printf("\033[1;34mMerge Sort - \033[1;36m%f\033[0m \033[1;34mseconds\033[0m\n", (float)(time_end - time_start) / CLOCKS_PER_SEC);
    if(method == 2) printf("\033[1;34mBuble Sort - \033[1;36m%f\033[0m \033[1;34mseconds\033[0m\n", (float)(time_end - time_start) / CLOCKS_PER_SEC);
    if(method == 3) printf("\033[1;34mMerge Sort(Reversed array(sorted even)) - \033[1;36m%f\033[0m \033[1;34mseconds\033[0m\n", (float)(time_end - time_start) / CLOCKS_PER_SEC);
}
/*==========================================================================*/