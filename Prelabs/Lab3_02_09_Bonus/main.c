#include "lab3b.h"

int main() {

    double *array = createDoubleArray(1900, 2000);

    for (int i = 1898; i < 2000; i++) {
        printf("%lf\n", array[i]);
    }

    freeDoubleArray(array, 1900);

    return 0;
}