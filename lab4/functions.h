#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputChoice(int *inputChoice){
    printf("Choose: keyboard input(1) or random input(2):\n");
    while (!scanf("%d", inputChoice) || *inputChoice != 1 && *inputChoice != 2 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        printf("Choose: keyboard input(1) or random input(2):\n");
        rewind(stdin);
    }
}

void arraySize(int *column, int *row){
    printf("Input the number of columns:\n");
    while (!scanf("%d", column) || *column < 1 || *column > 100 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        printf("Input the number of columns:\n");
        rewind(stdin);
    }
    printf("Input the number of rows:\n");
    while (!scanf("%d", row) || *row < 1 || *row > 100 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        printf("Input the number of rows:\n");
        rewind(stdin);
    }
}

void inputArrayElements(int сolumn, int row, int array[100][100]){
    printf("Enter array elements:\n");
    for(int i = 0; i < сolumn; i++)
        for(int j = 0; j < row; j++)
            while (!scanf("%d", &array[i][j]) || getchar() != '\n'){
                printf("Invalid input. Try again:\n\n");
                printf("Enter array elements:\n");
                rewind(stdin);
            }
}

void inputRandomLimit(int *limit){
    printf("Enter limit of random numbers of array:\n");
    while (!scanf("%d", limit) || *limit < 0 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        printf("Enter limit of random numbers of array:\n");
        rewind(stdin);
    }
}

void outputArray(int array[100][100], int col, int row){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++)
            printf("%5d ", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

void randomNumbers(int col, int row, int array[100][100]){
    srand(time(NULL));
    int random_number, limit = 0;
    inputRandomLimit(&limit);
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            array[i][j] = (rand() %  (2 * limit)) - limit;
            printf("%5d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void bubleSort(int col, int row, int array[100][100]){
    for(int k = 0; k < row - 1; k++)
        for(int i = 0; i < col; i++)
            for(int j = row - 1; j > k; j--)
                if(array[i][j] > array[i][j - 1]){
                    int tmp = array[i][j - 1];
                    array[i][j - 1] = array[i][j];
                    array[i][j] = tmp;
                }
}

void modBubleSort(int col, int row, int array[100][100], int *counter){
        for(int i = 0; i < col; i++)
            for(int j = col - 1; j > i; j--)
                if(counter[j] > counter[j - 1]){
                    int tmp = counter[j - 1];
                    counter[j - 1] = counter[j];
                    counter[j] = tmp;
                    for(int k = 0; k < row; k++){
                        int temp = array[j - 1][k];
                        array[j - 1][k] = array[j][k];
                        array[j][k] = temp;
                    }
                }
}