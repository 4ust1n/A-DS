#include "lab2.h"


/*
Comments
*/
float *readFloatFileIntoArray(FILE *fptr, int *length) {

    char buffer[10];

    fgets(buffer, 10, fptr);

    if (buffer[0] == (int)buffer[0] && buffer[0] > 0) {
        // arrLength = buffer[0];
        printf("%d\n", buffer[0]);
    }

    if (*length == 0) {
        printf("Failed to associate length.\n");
    }

    float *floatArrayPtr = malloc(sizeof(float) * (*length));

    // Verify pointer has allocated a block of memory.
    if (floatArrayPtr == NULL) {
        printf("Failed to allocate memory\n");
    }

    float finput = 0;

    for (int i = 1; i < *length; i++) {
        if (fscanf(fptr, "%f", &finput) != EOF) {
            floatArrayPtr[i] = finput;
        }
    }

    return floatArrayPtr;
}

void freeFloatArray(float *arrPtr) {

    free(arrPtr);
    arrPtr = NULL;

}

