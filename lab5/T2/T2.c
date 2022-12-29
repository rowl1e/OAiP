#include "functions.h"

void T2 () {
    int length, height;
    input_sizes_of_arrays(&length, &height);
    int** array = cc(length, height);
    array_filling(array, length, height);

    column_remover(array, &length, height);

    result(array, length, height);
    memory_freeing(array, length);
}

int main () {
    T2();
    system("pause");
    return 0;
}