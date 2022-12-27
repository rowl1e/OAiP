#include "strg.h"
#include "Merge Sort.h"

void T1 (int argc, char** argv) {
    if (argc == 1) {
        printf("\nThere is should be more than 1 argument.\n");
        return;
    }

    char** strs = (char**) calloc (argc - 1, sizeof(char*));
    int* sizes = (int*) calloc (argc - 1, sizeof(int));

    copy (argc, argv, strs, sizes);
    mergeSort(&sizes, &strs, 0, argc - 2);

    printf("\n");
    print_string(strs, argc);

    for (int i = 0; i < argc - 1; i++)
        free(strs[i]);
    free(strs);
    free(sizes);
}

int main (int argc, char** argv) {
    T1(argc, argv);
    printf("\n");
    system("pause");
    return 0;
}