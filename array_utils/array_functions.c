#include <stdio.h>
#include "../include/sum_interface.h"

int* get_array(size_t size) {
    int* array = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
        array[i] = i % 100;
    return array;
}

size_t get_size_from_file(char* filename) {
    size_t size = 0;
    int temp;
    FILE* file = fopen(filename, "rb");
    if (!file)
        return 0;
    while (!feof(file)) {
        if (fscanf(file, "%d", &temp) == 1) {
            size++;
        }
    }
    fclose(file);
    return size;
}

int* get_array_from_file(char* filename, size_t* size) {
    *size = get_size_from_file(filename);
    FILE* file = fopen(filename, "rb");
    if (!file)
        return NULL;
    int* array = calloc(*size, sizeof(int));
    int i = 0;
    while (!feof(file)) {
        if (fscanf(file, "%d", &array[i]) == 1) {
            i++;
        }
    }
    fclose(file);
    return array;
}

void free_array(int* array) {
    free(array);
}

void write_to_file(const char* filename, long long even, long long odd) {
    FILE* file = fopen(filename, "a+");
    if (!file)
        return;
    fprintf(file, "%lld %lld ", even, odd);
    fclose(file);
}