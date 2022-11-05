#include "functions.h"

//Задание 3
void task3(int size1, int size2, int *array1, int *array2){
    int result = 0, flag = 0, tmp = size2;
    for(int i = 0; i < tmp; i++)
        duplicateNumberRemover(&size2, &array2[0]);
    for(int i = 0; i < size2; i++){
        for(int j = 0; j < size2; j++){
            if(array1[i] < array2[j])
                continue;
            if(array1[i] > array2[j]){           
                result = array1[i];
                flag++;
                break;
            }
            if(array1[i] == array2[j])
                break;
        }
        if(flag == 1)
            break;
    }
    if(flag == 0)
        printf("There is no such number.\n");
    else
        printf("Result: %d\n", result);
}

int main(){
    int array_n[100], array_k[100], size_n = 0, size_k = 0, input = 0;
    inputChoice(&input);
    size_n = arraySizeTask3(size_n, 'n');
    size_k = arraySizeTask3(size_k, 'k');
    switch(input){
        case 1:
            inputArrayElements(size_n, &array_n[0], 'n');
            inputArrayElements(size_k, &array_k[0], 'k');
            break;
        case 2:
            randomNumbers(size_n, &array_n[0], 'n');
            randomNumbers(size_k, &array_k[0], 'k');
            break;
    }
    bubleSort(size_n, &array_n[0]);
    bubleSort(size_k, &array_k[0]);
    task3(size_n, size_k, &array_n[0], &array_k[0]);
    system("pause");
    return 0;
}