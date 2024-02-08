#include "lab1.h"

int main() {

    int *winner = malloc(sizeof(int));
    int *toss = malloc(sizeof(int));

    char player1[3] = "THH";
    char player2[3] = "HHT";
    
    int result = coinTossGame(player1, player2, winner, toss);
    printf("Result: %d\n", result);
    return 0;
}