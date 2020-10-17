#include <stdio.h>
#include "../include/sum_interface.h"

int validate_arguments(int argc, char *argv[]) {
    if (argc != 2) {
        printf("There must be two arguments, but got %d.\n", argc);
        return ERROR;
    }
    int size_int = atoi(argv[1]);
    if (size_int <= 0) {
        printf("There must number of elements (> 0), but got %d.\n", size_int);
        return ERROR;
    }
    if (size_int > 100000000) {
        printf("There must number of elements <= 100 000 000, but got %d.\n", size_int);
        return ERROR;
    }
    return SUCCESS;
}

int print_error(int code) {
    switch (code) {
        case ERROR:
            puts("Not valid arguments.");
            break;
        case ERROR_UNMAP:
            puts("Error with unmap.");
            break;
        case ERROR_FORK:
            puts("Error with fork.");
            break;
        case ERROR_ALLOC:
            puts("Error with allocation of memory.");
            break;
        default:
            break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int code = validate_arguments(argc, argv);
    if (code != SUCCESS)
        return print_error(code);
    size_t size = atoi(argv[1]);
    int* array = get_array(size);
    long long even, odd;
    code = set_sum(array, size, &even, &odd);
    if (code != SUCCESS) {
        free_array(array);
        return print_error(code);
    }
    printf("even_sum = %lld\nodd_sum = %lld\n", even, odd);
    free_array(array);
    return 0;
}