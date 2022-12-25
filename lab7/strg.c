char* get_str () {
    char* str;
    char c;
    int i = 0;
    str=(char*)calloc(1, 1);
    while(i <= 1)   //Skip space before letter
        while((c = getchar())!=EOF && c != '\n'){
            str = (char*)realloc (str, (i + 1) * sizeof(char));
            str[i] = c;
            i++;
        }
    str[i] = '\0';
    return str;
}

int str_len(char* str) {
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

int isletter_ (char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

