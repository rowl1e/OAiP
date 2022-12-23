#include <stdio.h> 
#include <time.h>
#include "getint.h"
#include "sorts.h"
#include "arr.h"

void T1();
void T2();

int main () {
    int task; 
    choice_of_two(&task);
    printf("Choose task:\n\tTask1 - 1\n\t Task2 - 2\n\n");
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
    arrayFilling(0, array, length, 0, 1);
    int count = 0;
    evenSize(array, length, &count);
    int** even = mc_2D(count, 2);

    int exit = 2;
    while (exit == 2) {
        printf("Choose sort method:\n\t1) Merge Sort\n\t2) Buble Sort\n\t3) Reverse Sort\n\n");
        int method = getint_minmax(1, 3);
        int* array_duplicate = mc_1D(length);
        copy(array, array_duplicate, length);
        evenArrayFilling(array, length, even, count);
        clock_t time_start, time_end;

        switch (method) {
            case 1:
                time_start = clock();
                mergeSort_MOD(even, 0, count - 1);
                time_end = clock();
                break;
            case 2:
                time_start = clock();
                bubleSort_MOD(even, count);
                time_end = clock();
                break;
            case 3:
                time_start = clock();
                Reverse_MOD(even, count);
                mergeSort_MOD(even, 0, count - 1);
                time_end = clock();
        }

        //Editing array_duplicate(replace unsorted even numbers with sorted ones)
        arrayEdit(array_duplicate, length, even, count);
        printf("\n\033[1;32mYour edited array is:\033[0m\n\n");
        outputArray_1D(array_duplicate, length);
        if(method == 1) printf("\033[1;34mMerge Sort - \033[1;36m%f\033[0m \033[1;34mseconds\033[0m\n", (float)(time_end - time_start) / CLOCKS_PER_SEC);
        if(method == 2) printf("\033[1;34mBuble Sort - \033[1;36m%f\033[0m \033[1;34mseconds\033[0m\n", (float)(time_end - time_start) / CLOCKS_PER_SEC);
        if(method == 3) printf("\033[1;34mMerge Sort(Reversed array(even)) - \033[1;36m%f\033[0m \033[1;34mseconds\033[0m\n", (float)(time_end - time_start) / CLOCKS_PER_SEC);
        
        printf("Do you want to continue?(1 - no, 2 - yes)\n");
        choice_of_two(&exit);
        free(array_duplicate);
        rewind(stdin);
    }
    free(array);
}

void T2() {
    printf("\nEnter height of cols:\n");
    int height = getint_min(1);
    printf("\nInput length of rows:\n");
    int length = getint_min(1);
    int** array = mc_2D(length, height);
    arrayFilling(array, 0, length, height, 2);

    printf("\033[1;36mBefore sort:\033[0m\n");
    sum_output (array, length, height);
    bubleSort_Rows(array, length, height);
    printf("\n\033[1;36mAfter sort:\033[0m\n");
    sum_output (array, length, height);

    printf("\n\033[1;32mYour edited array is:\033[0m\n\n");
    outputArray_2D(array, length, height);
    memoryFreeing_2D(array, height);
}