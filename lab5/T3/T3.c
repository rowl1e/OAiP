#include "functions.h"

void T3 () {
    printf("\nEnter height of cols:\n");
    int height = getint_min(1);

    printf("\nEnter sizes of rows:\n");
    int* length = cc_1D(height);
    for (int i = 0; i < height; i++)
        length[i] = getint_min(1) + 1;

    int** array = cc_2D(length, height);
    array_filling(array, length, height);

    printf("\nEnter k:\n");
    int k = getint();
    task3(array, length, height, k);

    printf("\n\033[1;32mYour edited array is:\033[0m\n\n");
    print_array(array, length, height);
    memory_freeing(array, height);
    free(length);
}

int main () {
    T3();
    system("pause");
    return 0;
}