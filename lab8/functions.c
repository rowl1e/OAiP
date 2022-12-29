#include <stdio.h>
#include <stdlib.h>

//Text function
void error () {
    printf("\033[1;31mInvalid input. Try again:\033[0m\n");
}

//getint
int getint () {
    int integer;
    while (!scanf("%d", &integer) || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}

int getint_min (int min) {
    int integer;
    while (!scanf("%d", &integer) || integer < min || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}

int getint_minmax (int min, int max) {
    int integer;
    while (!scanf("%d", &integer) || integer < min || integer > max || getchar() != '\n') {
            error();
            rewind(stdin);
    }
    return integer;
}

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

//Other
int shortest_word_size (char** str) {
    int shortest_word = INT_MAX;
    int length = str_len(*str);
    int letter_count = 0;
    for (int i = 0; i < length; i++){
        if (isletter_((*str)[i]) == 1 && isletter_((*str)[i + 1]) == 1)
            ++letter_count;
        if (isletter_((*str)[i]) == 1 && isletter_((*str)[i + 1]) == 0){
            ++letter_count;
            if(shortest_word > letter_count)
                shortest_word = letter_count;
            letter_count = 0;
        }
    }
    return shortest_word;
}

void copy_argv_to_strs (int argc, char** argv, char** strs, int* sizes) {
    for (int i = 1; i < argc; i++) {
        str_copy(argv[i], &strs[i - 1]);
        sizes[i - 1] = shortest_word_size(&strs[i - 1]);
        printf("\nShortest word size is %d;\n%s\n", sizes[i - 1], strs[i - 1]);
    }
}