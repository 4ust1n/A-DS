#include "lab3.h"

/*
    This function creates an array of integers 
    from a provided file and takes an amount of possible
    elements to be inside array.
*/
int * createIntArray(FILE *filePtr, int *length) {

    int *array = malloc(sizeof(int) * (*length));

    // Guard Clause
    if (array == NULL) {
        printf("Memory failed to be allocated.");
        return NULL;
    }

    int value = 0;

    while (fscanf(filePtr, "%d", &value) != EOF) {
        int i = 0;
        array[i] = value;
        i++;
    }

    return array;
}

float getArrayMean(int *) {

}

void freeIntArray(int *) {

}