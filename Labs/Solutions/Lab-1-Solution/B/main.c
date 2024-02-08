#include "lab1.h"

void printArray(int array[], int size) {
    for(int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    puts("");
}

int main() {
    int size = 5;
    int array[] = { 3, 1, 4, 7, 6 };
    int expected[] = { 3, 7, 4, 1, 6 };
    char str[] = "Hello, world!";

    int a = 0, b = 1;
    swap(&a, &b);
    if(!a || b) {
        printf("ERROR in swap: expected (1, 0); got (%d, %d)\n", a, b);
    }

    swapMaxMin(array, size);
    for(int i = 0; i < size; ++i) {
        if(array[i] != expected[i]) {
            printf("ERROR in swapMaxMin; index %d\n", i);
            printf("Expected: ");
            printArray(expected, size);
            printf("Got     : ");
            printArray(array, size);
        }
    }

    int ec = 0;
    char c = 0;

    ec = lastChar(str, &c);
    if(c != '!') {
        printf("ERROR in lastChar; expected %c, got %c\n", str[12], c);
    }
    if(ec) {
        puts("ERROR in lastChar; unexpectedly returned failure");
    }

    ec = lastChar("", &c);
    if(!ec) {
        puts("ERROR in charAt; unexpectedly returned success");
    }

}

