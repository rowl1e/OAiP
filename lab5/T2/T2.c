#include "functions.h"

void T2 () {
    printf("Enter length:\n");
    int length = getint_min(1);
    printf("\nEnter height:\n");
    int height = getint_min(1);
    int** array = mc(length, height);
    array_filling(array, length, height);

    column_remover(array, &length, height);

    // array = (int**) realloc (array, length * sizeof(int*));
    
    result(array, length, height);
    memory_freeing(array, height);
}

int main () {
    T2();
    system("pause");
    return 0;
}