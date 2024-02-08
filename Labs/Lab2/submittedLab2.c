#include "lab2.h"

// Makes an array by creating new memory.
int *makeArray(int size) {

    int *arrayPtr = malloc(sizeof(int) * size);

    if (arrayPtr == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        arrayPtr[i] = 0;
    }

    return arrayPtr;
}

/*
*   Find the index of a specific element in an array.
*
*   Parameters:
*   int *array - A pointer to an array.
*   int size - Size of an array.
*   int element - Query of an int to be found.
*
*   Returns:
*   -1 if did not find element, other the index.
*/

int indexOf(int *array, int size, int element) {

    for (int i = 0; i < size; i++) {
        if (element == array[i]) {
            return i;
        }
    }
    return -1;
}

/*
*   Slices an array given by the caller via pointer.
*
*   Parameters:
*   int *array - Pointer to an array.
*   int size - Size of array.
*   int begin - Begin of new array via a specific element.
*   int end - End of a new array via a specific element.
*
*   Returns:
*   -1 if either being or end element was not found, size of new array otherwise.
*/

int sliceArray(int *array, int size, int begin, int end, int **result) {

    int indexOfBegin = indexOf(array, size, begin);
    int indexOfEnd = indexOf(array, size, end);

    if (indexOfBegin == -1 || indexOfEnd == -1) {
        return -1;
    }

    *result = &array[indexOfBegin];

    return (indexOfEnd - indexOfBegin) + 1;
}

/*
* Frees the associated pointer.
* 
* Parameter:
* int **array: Takes in a specific pointer of another pointer.
*
* Returns:
* void.
*/
void freeArray(int **array) {
    free(array);
    *array = NULL;
}

// I FORGOT THE the pointer inside the free()!!!
// I AM UPSET. THIS IS CRAZY. LIKE WHY MEEE. I ALMOST HAD IT.