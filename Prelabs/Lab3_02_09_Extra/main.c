#include "lab3e.h"

int main() {

    int length = 5;
    size_t datatypeSize = sizeof(double);

    double *arrayPtr = createArray(&length, &datatypeSize);

    for (int i = 0; i < 5; i++) {
        printf("ADDY: %p\n", (void *)&arrayPtr[i]);
         printf("VALUE: %f\n", arrayPtr[i]);
    }

    free(arrayPtr);

    return 0;
}