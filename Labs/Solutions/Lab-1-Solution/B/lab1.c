#include "lab1.h"

/* swap:
    This function takes two int pointers; a, b.
    It swaps the values being pointed to, such
    that a1, b1 == b2, a2.
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* swapMaxMin:
    This function takes an int array, and the size
    of the array. It finds and swaps the min and
    max values in the array, so long as there are
    no duplicates. If the swap was performed, it
    return 0, otherwise 1.
*/
int swapMaxMin(int array[], int size) {
    int minIndex = 0, maxIndex = 0;

    // we can start the loop at 1 since min/max start at 0
    for(int i = 1; i < size; ++i) {
        if(array[i] < array[minIndex]) {
            minIndex = i;
        } else if(array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }

    if(array[minIndex] == array[maxIndex]) {
        return 1;
    }

    // We could also use `&array[minIndex]` to get the address
    // But this is easier to read
    swap(array + minIndex, array + maxIndex);
    return 0;
}


/* lastChar:
    This function takes a C string, and returns
    by reference the character at the last index.
    If the string is empty, it returns 1, or 0
    otherwise.
*/
int lastChar(char str[], char *result) {
    for(int i = 0; str[i] != 0; ++i) {
        if(str[i + 1] == 0) {
            *result = str[i];
            return 0;
        }
    }

    return 1;
}

