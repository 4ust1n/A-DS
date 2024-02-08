#include "lab2.h"

/* makeArray
    This function takes an int which
    represents the requested size of
    the array to create. It allocates
    and returns a pointer to the array
    on success, or NULL on failure.
    The memory is 0-initialized on
    success.

    Param: int size;    The size of the array to create
*/
int * makeArray(int size) {
    int *array = malloc(sizeof(int) * size);

    if(array) {
        for(int i = 0; i < size; ++i) {
            array[i] = 0;
        }
    }

    return array;
}


/* addressOf
    This function takes an array,
    the size of the array, and a
    query element. It returns the
    address of the element on
    success, or NULL if the element
    is not found.
    
    Param: int *array;      The array to search
    Param: int size;        The size of the array
    Param: int element;     The element to search for
*/
int * addressOf(int *array, int size, int element) {
    for(int i = 0; i < size; ++i) {
        if(array[i] == element) {
            return array + i;
        }
    }

    return NULL;
}


/* sliceArray
    This function takes an array, the size of the array,
    and two boundary elements. It slices the array around
    the boundary elements, so long as both exist in the
    array. The address of the slice will be placed in the
    result pointer and the function will return the size
    of the slice on success, or -1 on failure.

    Param: int *array;      The array to slice
    Param: int size;        The size of the array
    Param: int begin;       The element at the beginning of the slice
    Param: int end;         The element at the end of the slice
    Param: int **result;    The start address of the new array
*/
int sliceArray(int *array, int size, int begin, int end, int **result) {

    int *beginAddr = addressOf(array, size, begin);
    int *endAddr = addressOf(array, size, end);

    if(!beginAddr || !endAddr) {
        return -1;
    }

    *result = beginAddr;

    int newSize = ((endAddr - array) - (beginAddr - array)) + 1;

    return newSize;
}

/* freeArray
    This function takes a pointer
    to a pointer to an int array.
    It frees the array, and sets
    the referenced pointer to NULL
*/
void freeArray(int **array) {
    free(*array);
    *array = NULL;
}

