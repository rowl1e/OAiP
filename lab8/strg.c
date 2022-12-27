#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

char* get_str () {
    char* str;
    char c;
    int i = 0;
    str = (char*) calloc (1, sizeof(char));
    while(i <= 1)
        while((c = getchar())!= EOF && c != '\n'){
            str = (char*) realloc (str, (i + 1) * sizeof(char));
            str[i] = c;
            i++;
        }
    str[i] = '\0';
    return str;
}

int str_len(char* str) {
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int isletter_ (char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

void str_copy(char* str1, char** str2) {
    int i = 0;
    int len = str_len(str1);
    (*str2) = (char*) calloc (len + 1, sizeof(char));
    while (str1[i] != '\0') {
        (*str2)[i] = str1[i];
        i++;
    }
    (*str2)[i] = '\0';
}

void print_string(char** str, int length) {
    for (int i = 0; i < length - 1; i++)
        printf("%s\n", str[i]);
}

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

void copy (int argc, char** argv, char** strs, int* sizes) {
    for (int i = 1; i < argc; i++) {
        str_copy(argv[i], &strs[i - 1]);
        sizes[i - 1] = shortest_word_size(&strs[i - 1]);
        printf("Shortest word size is %d;\n\t%s\n", sizes[i - 1], strs[i - 1]);
    }
}