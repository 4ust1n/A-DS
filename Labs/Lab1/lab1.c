#include "lab1.h"

/* 
 * Pass in two integers and swap their places using pass by reference.
 *
 * Parameters:
 * int *a - pointer to integer a.
 * int *b - pointer to integer b.
 * 
 * Returns: 
 * - void
*/
void swap(int *a, int *b) {
    
    // Temporary home for a for assignment to b.
    int c = *a;

    // Swap numbers
    *a = *b;
    *b = c;
}

/*
 * Find the min and max of an array and swap them by calling swap().
 * 
 * Parameters: 
 * int array[] - The array of integers.
 * int size - The size of the array.
 * 
 * Returns:
 * 1 if max and min are the same, otherwise 0.
 * 
*/
int swapMaxMin(int array[], int size) {

    int *min = malloc(sizeof(int));
    int *max = malloc(sizeof(int));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i] > array[j] && array[i] > *max) {
                *max = array[i];
            } 
            if (array[i] < array[j] && array[i] < *max) {
                *min = array[i];
            }
        }
    }

    if (*max == *min) {
        return 1;
    }

    swap(min, max);

    array[0] = *max;
    array[size - 1] = *min;

    free(min);
    free(max);

    return 0;

}

/*
 * Find a character at a specific index of a string and save it to result parameter.
 * 
 * Parameters:
 * char str[] - The provided string.
 * int index - The index to be checked against string.
 * char *result - Pointer to the character found at specified index.
 * 
 * Returns:
 * 1 if index is not valid operation on the string, otherwise 0.
*/
int charAt(char str[], int index, char *result) {

    int foundNullTerminator = 0;
    int length = 0;

    // Find the length of the array.
    while (!foundNullTerminator) {
        if (str[length] == '\0') {
            foundNullTerminator = 1;
        } else {
            length++;
        }

    }

    if (index < 0 || index >= length) {
        return 1;
    }

    *result = str[index];

    return 0;
}