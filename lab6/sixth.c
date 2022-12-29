#include <stdio.h> 
#include <time.h>
#include "sorts.h"
#include "arr.h"

void T1();
void T2();

int main () {
    printf("Choose task:\n\tTask1 - 1\n\tTask2 - 2\n\n");
    int task = getint_minmax(1, 2); 
    switch (task) {
        case 1:
            T1();
            break;
        case 2:
            T2();
    }
    system("pause");
    return 0;
}

//Tasks
void T1 () {
    printf("\nInput length of array:\n");
    int length = getint_min(1);
    int* array = mc_1D(length);
    array_filling(0, array, length, 0, 1);

    int even_length = even_count(array, length);
    int** even = mc_2D(even_length, 2);

    int continue_ = 1;
    while (continue_ == 1) {
        printf("Choose sort method:\n\t1) Merge Sort\n\t2) Buble Sort\n\t3) Reverse Sort\n\n");
        int method = getint_minmax(1, 3);
        int* array_duplicate = mc_1D(length);
        copy_array1_to_array2(array, array_duplicate, length);
        even_filling(array, length, even, even_length);
        clock_t time_start, time_end;

        switch (method) {
            case 1:
                time_start = clock();
                mergeSort_MOD(even, 0, even_length - 1);
                time_end = clock();
                break;
            case 2:
                time_start = clock();
                bubleSort_MOD(even, even_length);
                time_end = clock();
                break;
            case 3:
                time_start = clock();
                mergeSort_MOD(even, 0, even_length - 1);
                reverse_MOD(even, even_length);
                time_end = clock();
        }

        //Editing array_duplicate(replace unsorted even numbers with sorted ones)
        array_edit(array_duplicate, length, even, even_length);

        printf("\n\033[1;32mYour edited array is:\033[0m\n\n");
        print_array_1D(array_duplicate, length);
        free(array_duplicate);
        time_result (time_start, time_end, method);
        
        printf("Do you want to continue?(0 - no, 1 - yes)\n");
        continue_ = getint_minmax(0, 1);
        rewind(stdin);
    }
    free(array);
    memory_freeing_2D(even, 2);
}

void T2() {
    printf("\nEnter height of cols:\n");
    int height = getint_min(1);
    printf("\nInput length of rows:\n");
    int length = getint_min(1);
    int** array = mc_2D(length, height);
    array_filling(array, 0, length, height, 2);

    printf("\033[1;36mBefore sort:\033[0m\n");
    sum_print (array, length, height);
    bubleSort_rows(array, length, height);
    printf("\n\033[1;36mAfter sort:\033[0m\n");
    sum_print (array, length, height);

    printf("\n\033[1;32mYour edited array is:\033[0m\n\n");
    print_array_2D(array, length, height);
    memory_freeing_2D(array, height);
}