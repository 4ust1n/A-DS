#include "lab1.h"

int main() {

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    *a = 2;
    *b = 4;

    swap(a, b);
    printf("A: %d, B: %d\n", *a, *b);

    free(a);
    free(b);

    int array[] = { 7, 5, 1 };

    printf("Arr Min: %d, [%d] Arr Max: %d\n", array[0], array[1], array[2]);
    int result = swapMaxMin(array, 3);
    printf("MaxMin Result: %d\n", result);
    printf("Arr Min: %d, [%d] Arr Max: %d\n", array[0], array[1], array[2]);

    char *charr = malloc(sizeof(char));
    char input[] = "2050";

    int charAtResult = charAt(input, 3, charr);

    printf("%c\n", *charr);

    printf("%d\n", charAtResult);

    free(charr);

    return 0;
}