#include "functions.h"

//Задание 1.1
void task11(int arraySize, float *array){
    float result = 1;
    for(int i = 0; i < arraySize; i++){
        if(array[i] > 0)
            result *= array[i];
    }
    printf("Result: %.2f\n", result);
}

//Задание 1.2
void task12(int arraySize, float *array){
    int x = 0;
    float result = 0, min = INT_MAX;
    for(int i = 0; i < arraySize; i++){
        if(array[i] < min){  
            min = array[i];
            x = i;
        }
    }   
    for(int i = 0; i < x; i++)
        result += array[i];
    printf("Result: %.2f\n", result);
}

int main(){
    int input = 0, task = 0, size = 0;
    float result, array[100];
    inputChoice(&input);
    arraySizeTask1(&size);
    taskChoice(&task);
    switch(input){
        case 1:
            inputArrayElementsTask1(size, &array[0]);
            break;
        case 2:
            randomNumbersTask1(size, &array[0]);
            break;
    }
    switch(task){
        case 1:
            task11(size, &array[0]);
            break;
        case 2:
            task12(size, &array[0]);
            break;
    }
    system("pause");
    return 0;
}