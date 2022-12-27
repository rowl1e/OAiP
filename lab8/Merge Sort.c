#include <stdio.h>
#include <stdlib.h>

//Merge Sort
void merge (int** array, char*** strs, int start, int end, int mid);

void mergeSort (int** array, char*** strs, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(array, strs, start, mid);
        mergeSort(array, strs, mid + 1, end);
        merge(array, strs, start, end, mid);
    }
}

void merge (int** array, char*** strs, int start, int end, int mid) {
	int left = start;
	int right = mid + 1;
	int length = end - start + 1;
	int* temp = (int*) malloc (length * sizeof(int));
	char** tempstrs = (char**) calloc (length, sizeof(char*));
	int k = 0;
	while ((left <= mid) && (right <= end)) {
		if ((*array)[left] < (*array)[right]) {
			temp[k] = (*array)[left];
			tempstrs[k] = (*strs)[left];
			left++;
		}
		else {
			temp[k] = (*array)[right];
			tempstrs[k] = (*strs)[right];
			right++;
		}
		k++;
	}
    while (left <= mid) {
		temp[k] = (*array)[left];
		tempstrs[k] = (*strs)[left];
		left++;
        k++;
	}
    while (right <= end) {
		temp[k] = (*array)[right];
		tempstrs[k] = (*strs)[right];
		right++;
        k++;
	}
	for (int i = 0; i < length; i++) {
		(*array)[start + i] = temp[i];
		(*strs)[start + i] = tempstrs[i];
	}
	free(temp);
	free(tempstrs);
}