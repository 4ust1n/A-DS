#include "lab2.h"

int main() {

    //////////////////////////
    // makeArray()
    //////////////////////////
    int *arr = makeArray(5);

    for (int i = 0; i < 5; i++) {
        printf("makeArray() - %d\n", arr[i]);
    }

    printf("\n");

    //////////////////////////
    // indexOf()
    //////////////////////////
    int arr2[] = {9, 3, 2, 8, 7, 5};
    int findIndex = indexOf(arr2, 6, 8);
    printf("indexOf() - %d\n", findIndex);

    printf("\n");

    //////////////////////////
    // sliceArray()
    //////////////////////////

    int **result = malloc(sizeof(int) * 7);

    int arr3[] = { 2 , 9 , 4 , 3 , 0 , 7 , 1 };
    int slice = sliceArray(arr3, 7, 2, 1, result);
    printf("sliceArray() Size - %d\n", slice);
    printf("sliceArray() Result - %d\n", **result);
    for (int *i = *result; *i < slice; i++) {
        printf("%d\n", *i);
        // printf("sliceArray() - Index: %ls | Value: %d\n", i, *i);
    }

    //////////////////////////
    // freeArray()
    //////////////////////////
    freeArray(result);

    return 1;
}