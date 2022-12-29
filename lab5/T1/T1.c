#include "functions.h"

void T1 () {
    int size1, size2;
    input_sizes_of_arrays(&size1, &size2);
    int* array1 = (int*) malloc (size1 * sizeof(int));
    int* array2 = (int*) malloc (size2 * sizeof(int));

    input_array_elements(array1, array2, size1, size2);
    print_arrays(array1, array2, size1, size2);

    bubleSort(array2, size2);
    duplicate_number_remover(array2, &size2);
    task1(array1, array2, &size1, size2);

    result(array1, size1);
    free(array1);
    free(array2);
}

int main () {
    T1();
    system("pause");
    return 0;
}