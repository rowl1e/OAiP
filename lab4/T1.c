#include "functions.h"

//Задание 1
void task1(int array[100][100], int col, int row){
    int counter[100], tempMas[100][100];
    for(int i = 0; i < col; i++)
        for(int j = 0; j < row; j++)
            tempMas[i][j] = array[i][j];
    bubleSort(col, row, tempMas);
    for(int i = 0; i < col; i++){
        counter[i] = 0;
        for(int j = 0; j < row - 1; j++)
            if(tempMas[i][j] == tempMas[i][j + 1])
                counter[i]++;
    }
    modBubleSort(col, row, array, &counter[0]);
    printf("Sorted array:\n");
    outputArray(array, col, row);
    for(int i = 0; i < row; i++){
        int flag = 0;
        for(int j = 0; j < col; j++)
            if(array[j][i] >= 0)
                flag += 1;
        if(flag == col){
            printf("First column without negative numbers is %d.\n", i);
            break;
        }
        if(i == row - 1 && flag != col)
            printf("There is no such column.\n");
    }
}

int main(){
    int array[100][100], col, row, input;
    inputChoice(&input);
    arraySize(&col, &row);

    switch (input){
        case 1:
            inputArrayElements(col, row, array);
            break;
        case 2:
            randomNumbers(col, row, array);
            break;
    }

    task1(array, col, row);
    system("pause");
    return 0; 
}