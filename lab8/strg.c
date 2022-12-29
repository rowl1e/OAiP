#include <stdio.h>
#include <stdlib.h>

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

int letter_count_ (char** str, int length) {
    int count = 0;
    for (int i = 0; i < length; i++)
        if (isletter_((*str)[i]))
            count++;
    return count;
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