#include "functions.h"

//Задание 2
void task2(int array[100][100], int col, int row){
    int flag[100], flg = 0;
    for(int i = 0; i < col; i++)
        for(int j = 0; j < row; j++)
            if(array[i][j] == 0){
                flag[i] = 1;
                break;
            }
    for(int i = 0; i < col; i++)
        if(flag[i] == 0){
            flg = 0;
            break;
        }
    for(int i = 0; i < col; i++)
        for(int j = 0; j < row; j++)
            if(array[i][j] < 0)
                array[i][j] = 0;
    printf("Result:\n");
    outputArray(array, col, row);
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
    
    task2(array, col, row);
    system("pause");
    return 0; 
}