#include "lab2.h"

int main() {
    int size = 10;
    int array[] = { 7, 2, 5, 8, 4, 9, 3, 0, 1, 6 };

    puts("----------------RUNNING TESTS----------------");

    int *testArr = makeArray(size);
    if(!testArr) {
        puts("ERROR: makeArray unexpectedly returned NULL");
    } else {
        for (int i = 0; i < size; ++i)
        {
            if (testArr[i] != 0)
            {
                printf("ERROR: array[%d] not 0-initialized\n", i);
                break;
            }
        }
    }


    int *test = addressOf(array, size, 4);
    if(test != (array + 4)) {
        puts("ERROR: addressOf returned unexpected address");
        printf("Expected %p, got %p\n", (void *)(array + 4), (void *)test);
    }

    test = addressOf(array, size, -255);
    if(test) {
        puts("ERROR: addressOf unexpectedly returned success");
    }


    int *slice;
    int sliceSize = sliceArray(array, size, 9, 1, &slice);
    if(sliceSize != 4) {
        printf("ERROR: slice returned size of %d, expected %d\n", sliceSize, 4);
    }
    if(slice != array + 5) {
        puts("ERROR: slice returned unexpected begin addres");
        printf("Expected %p, got %p\n", (void *)(array + 5), (void *)slice);
    }

    sliceSize = sliceArray(array, size, 9, -25, &slice);
    if(sliceSize != -1) {
        printf("ERROR: slice unexpectedly returned success. Got %d\n", sliceSize);
    }

    sliceSize = sliceArray(array, size, 25, 9, &slice);
    if (sliceSize != -1) {
        printf("ERROR: slice unexpectedly returned success. Got %d\n", sliceSize);
    }

    puts("----------------FREEING ARRAY----------------");
    freeArray(&testArr);
    if(testArr) {
        puts("ERROR: freeArray did not nullify array");
    }
}

