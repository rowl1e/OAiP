#include "functions.h"

//Задание 3
void task3(int array[100][100], int col, int row){
    int result = 0, m = 0, n = 0, x = col % 2, y = row % 2;
    switch(x){
        case 0:
            m = col / 2;
            break;
        case 1:
            m = (col + 1) / 2;
    }
    switch(y){
        case 0:
            n = row / 2;
            break;
        case 1:
            n = (row + 1) / 2;
    }
    for(int i = m; i < col; i++)
        for(int j = n; j < row; j++)
            result += array[i][j];
    printf("Result is %d\n", result);
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

    task3(array, col, row);
    system("pause");
    return 0; 
}