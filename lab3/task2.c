#include "functions.h"

//Задание 2
void task2k(int arraySize, int *array){
    int min1, min2, min3, min4, flag;
    flag = elementsChecker(arraySize, &array[0]);
    if(flag == 0){
        for(int i = 0, min1 = min2 = min3 = min4 = INT_MAX; i < arraySize; i++){
            for(int j = 0; j < arraySize; j++){
                if(array[j] < min1)
                    min1 = array[j];
                if(array[j] < min2 && array[j] != min1)
                    min2 = array[j];
                if(array[j] < min3 && array[j] != min1 && array[j] != min2)
                    min3 = array[j];
                if(array[j] < min4 && array[j] != min1 && array[j] != min2 && array[j] != min3)
                    min4 = array[j];
            }
        }
        printf("Result: %d\n", min4);
    }
}

int main(){
    int array[100], input = 0, size = 0;;
    inputChoice(&input);
    arraySizeTask2(&size);
    switch(input){
        case 1:
            inputArrayElements(size, &array[0], '\0');
            break;
        case 2:
            randomNumbers(size, &array[0], '\0');
            break;
    }
    task2k(size, &array[0]);
    system("pause");
    return 0;
}