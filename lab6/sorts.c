#include <stdio.h>
#include <stdlib.h>

//Merge Sort Modified
void merge_MOD (int** array, int start, int end, int mid);

void mergeSort_MOD (int** array, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort_MOD(array, start, mid);
        mergeSort_MOD(array, mid + 1, end);
        merge_MOD(array, start, end, mid);
    }
}

void merge_MOD (int** array, int start, int end, int mid) {
	int left = start;
	int right = mid + 1;
	int length = end - start + 1;
	int* temp = (int*) malloc (length * sizeof(int));

	int k = 0;
	while ((left <= mid) && (right <= end)) {
		if (array[0][left] < array[0][right]) {
			temp[k] = array[0][left];
			left++;
		}
		else {
			temp[k] = array[0][right];
			right++;
		}
		k++;
	}
    while (left <= mid) {
		temp[k] = array[0][left];
		left++;
        k++;
	}
    while (right <= end) {
		temp[k] = array[0][right];
		right++;
        k++;
	}
	for (int i = 0; i < length; i++){
		array[0][start + i] = temp[i];
    }
	free(temp);
}

//Buble Sort Modified
void bubleSort_MOD (int **array, int length) {
    for (int i = 0; i < length - 1; i++)
        for (int j = (length - 1); j > i; j--)
            if (array[0][j] < array[0][j - 1]) {
                int tmp = array[0][j - 1];
                array[0][j - 1] = array[0][j];
                array[0][j] = tmp;
            }
}

//Buble Sort Rows
int sum_elements_of_row (int** array, int length, int i) { 
    int sum = 0;
    for (int j = 0; j < length; j++)
        sum = sum + array[i][j];
    return sum;
}

void bubleSort_Rows (int** array, int length, int height) {
    for (int j = 0; j < height; j++)
        for (int i = 0; i < height - 2; i = i + 2)
            if (sum_elements_of_row(array, length, i) < sum_elements_of_row(array, length, i + 2))
                for (int j = 0; j < length; j++) {
                    int temp = array[i][j];
                    array[i][j] = array[i + 2][j];
                    array[i + 2][j] = temp;
                }
}

//Reverse
void Reverse_MOD (int** array, int length) {
	for (int i = 0; i < length / 2; i++) {
		int temp = array[0][i];
		array[0][i] = array[0][length - 1 - i];
		array[0][length - 1 - i] = temp;
	}
}