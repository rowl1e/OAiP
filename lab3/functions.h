#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void inputChoice(int *inputChoice){
    printf("Choose: keyboard input(1) or random input(2):\n");
    while (!scanf("%d", inputChoice) || *inputChoice != 1 && *inputChoice != 2 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        printf("Choose: keyboard input(1) or random input(2):\n");
        rewind(stdin);
    }
}

void taskChoice(int *taskChoice){
    printf("Choose:\n\t1)product of positive array elements(1)\n\t2)the sum of the array elements up to the minimum element(2)\n");
    while (!scanf_s("%d", taskChoice) || *taskChoice != 1 && *taskChoice != 2 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        printf("Choose:\n\t1)product of positive array elements(1)\n\t2)the sum of the array elements up to the minimum element(2)\n");
        rewind(stdin);
    }
}

void arraySizeTask1(int *arraySize){
        printf("Input the size of array:\n");
    while (!scanf("%d", arraySize) || *arraySize < 1 || *arraySize > 100 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        printf("Input the size of array:\n");
        rewind(stdin);
    }
}

void arraySizeTask2(int *arraySize){
        printf("Input the size of array:\n");
    while (!scanf("%d", arraySize) || *arraySize < 4 || *arraySize > 100 || getchar() != '\n'){
        if(*arraySize>0 && *arraySize<4)
            printf("In such array, 4th minimal element of the array does not exist.\nTry again:\n");
        else        
            printf("Invalid input. Try again:\n\n");
            printf("Input the size of array:\n");
        rewind(stdin);
    }
}

int arraySizeTask3(int arraySize, char symbol){
    printf("Input the size of array %c:\n", symbol);
    while (!scanf("%d", &arraySize) || arraySize < 1 || arraySize > 100 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        rewind(stdin);
    }
    return arraySize;
}

void inputArrayElementsTask1(int arraySize, float *array){
    printf("Enter array elements:\n");
    for(int i = 0; i < arraySize; i++)
        while (!scanf_s("%f", &array[i]) || getchar() != '\n'){
            printf("Invalid input. Try again:\n");
            rewind(stdin);
        }
}

void inputArrayElements(int arraySize, int *array, char symbol){
    printf("Enter array %c elements:\n", symbol);
    for(int i = 0; i < arraySize; i++)
        while (!scanf("%d", &array[i]) || getchar() != '\n'){
            printf("Invalid input. Try again:\n\n");
            printf("Enter array %c elements:\n", symbol);
            rewind(stdin);
        }
}

//Случайные вещественные числа для задания 1
void randomNumbersTask1(int arraySize, float *array){
    srand(time(NULL));
    int a, limit, random;
    float checker;
    printf("Enter limit of random numbers:\n");
    while (!scanf("%d", &limit) || limit < 0 || getchar() != '\n'){
        printf("Invalid input. Try again:\n");
        printf("Enter limit of random numbers:\n");
        rewind(stdin);
    }
    for(int i = 0; i<arraySize; i++){
        a = rand() % 100;
        random = (rand() %  (2 * limit)) - limit;
        checker = a / 100.0 + random; 
        if(checker < limit)
            array[i] = checker;
        else 
            array[i] = random - a / 100.0;
        printf("array[%d] = %.2f\n", i, array[i]);
    }
}

//Случайные целые числа
void randomNumbers(int arraySize, int *array, char symbol){
    srand(time(NULL));
    int random_number, limit;
    printf("Enter limit of random numbers of array %c:\n", symbol);
    while (!scanf("%d", &limit) || limit < 0 || getchar() != '\n'){
        printf("Invalid input. Try again:\n\n");
        printf("Enter limit of random numbers of array %c:\n", symbol);
        rewind(stdin);
    }
    for(int i = 0; i < arraySize; i++){
        array[i] = (rand() %  (2 * limit)) - limit;
        printf("array[%d] = %d\n", i, array[i]);
    }
}


//Проверка на наличие повторяющихся элементов
int elementsChecker(int arraySize, int *array){
    int flag = 0, checker;
    printf("Checking:\n");
    for(int i = 0; i < arraySize; i++)
        if(array[i] != array[i+1]){
            flag++;
        }
    if(flag < 4){
        printf("\tIn such array, 4th minimal element of the array does not exist.\n");
        checker = 1;
    }
    else{
        printf("\tThis array fits.\n");
        checker = 0;
    }
    return checker;
}

void bubleSort(int arraySize, int *array){
    for(int i = 0; i < arraySize - 1; i++)
        for(int j = (arraySize - 1); j > i; j--)
            if(array[j] > array[j - 1]){
                int tmp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = tmp;
            }
}

void duplicateNumberRemover(int *n, int *array){
    for(int i = 0; i < (*n); i++)
        for(int j = i + 1; j < (*n); j++)
            if(array[i] == array[j]){
                for(int k = j; k < (*n) - 1; k++)
                    array[k] = array[k+1];
                (*n)--;
            }
}
