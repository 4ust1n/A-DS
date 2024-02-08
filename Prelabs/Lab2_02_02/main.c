#include "lab2.h"

int main() {

    FILE *fptr = fopen("floats.txt", "r");
    int length = 0;

    float *result = readFloatFileIntoArray(fptr, &length);

    printf("Result: %f\n", *result);

    return 1;
}