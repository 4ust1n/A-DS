#include "lab1.h"
#include <string.h>

int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses) {

    printf("%ld\n", sizeof(*player1) / sizeof(player1[0]));

    char alice[3] = "HHT";
    char bob[3] = "THH";

    for (int i = 0; i < ((sizeof(*player1)) / (sizeof(player1[0]))); i++) {
        printf("[1] %d\n", i);

        if (alice[i] != player1[i]) {

            printf("Character '%c' does not match sequence '%s' at index %d-\n", player1[i], alice, i);
            return 1;
        }
    }

    for (int i = 0; i < ((sizeof(*player2)) / (sizeof(player2[0]))); i++) {

        printf("[2] %d\n", player1[2]);

        if (bob[i] != player2[i]) {

            printf("Character '%c' does not match sequence '%s' at index %d.\n", player2[i], bob, i);
            return 2;
        }
    }


    char *sequence = malloc(3 * (sizeof(char)));
    sequence = "";


    // By default, 0 represents false, while 1 represents true.
    int sequenceFound = 0;

    while (!sequenceFound) {

        int toss = rand() % 2;

        // If true, toss is heads, otherwise tails.
        if (toss) {
            printf("%c", 'H');
            // for (int i = 0; i < sizeof(*sequencePtr) / sizeof(sequencePtr[0]); i++) {

            // }
        } else {
            printf("%c", 'T');
        }

        if (strcmp(sequence, alice) || strcmp(sequence, bob)) {

        }

        sequenceFound = 1;

    }

    return 0;
}