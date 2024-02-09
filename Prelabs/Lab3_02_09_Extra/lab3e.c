#include "lab3e.h"

void * createArray(int *length, size_t *datatypeSize) {
    
    void *array = malloc(*length * *datatypeSize);

    return array;
}

int getArraySize(void *array) {
    return 0;
}

void freeArray(void *array) {
    free(array);
    array = NULL;
}