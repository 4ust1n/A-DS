#include "lab3b.h"

double * createDoubleArray(int minIndex, int maxIndex) {

    double *array = malloc((maxIndex - minIndex) * sizeof(double));

    for (int i = minIndex; i < maxIndex; i++) {
        array[i] = 2;
    }

    return array;
}

void freeDoubleArray(double *array, int minIndex) {

    free(array);

}