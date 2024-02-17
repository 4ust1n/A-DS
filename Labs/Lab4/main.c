#include "lab4.h"

int main() {

    GameBoard *newGame = newBoard();

    // Check init memory.
    if (!newGame) {
        printf("UH OH\n");
    }
    if (newGame) {
        printf("WE GOOD\n");
    }

    if(getShotsTaken(newGame) != 0) {
        puts("ERROR: nonzero default for shots taken\n");
    }
    if(getHits(newGame) != 0) {
        puts("ERROR: nonzero default for hits\n");
    }
    if(getScore(newGame) != 0) {
        puts("ERROR: nonzero default for score\n");
    }

    // Check initial values;
    printf("[INIT NON-FUNCTION] Shots: %d, Hits: %d, Score: %f\n", newGame->shots, newGame->hits, newGame->score);

    // Check initial values via function;
    printf("[INIT FUNCTIONS] Shots: %d, Hits: %d, Score: %f\n", getShotsTaken(newGame), getHits(newGame), getScore(newGame));
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("[BEFORE] Cell: %d, Value: %d\n", i, newGame->arena[i]);
    }

    // Check the amount of free cells before placement.
    printf("[FREE CELLS BEFORE]- %d\n", countFreeCells(newGame));

    // Test placeShip
    int one = placeShip(newGame, 8);
     printf("[FREE CELLS 1]- %d\n", countFreeCells(newGame));
    int two = placeShip(newGame, 2);
     printf("[FREE CELLS 2]- %d\n", countFreeCells(newGame));
    int three = placeShip(newGame, 3);
     printf("[FREE CELLS 3]- %d\n", countFreeCells(newGame));
    int four = placeShip(newGame, 19);
     printf("[FREE CELLS 4]- %d\n", countFreeCells(newGame));
    int five = placeShip(newGame, 22);
     printf("[FREE CELLS 5]- %d\n", countFreeCells(newGame));
    int six = placeShip(newGame, 28);
     printf("[FREE CELLS 6]- %d\n", countFreeCells(newGame));
    int seven = placeShip(newGame, 6);
     printf("[FREE CELLS 7]- %d\n", countFreeCells(newGame));
    int eight = placeShip(newGame, 8);

    // Check the amount of free cells after placement.
    printf("[FREE CELLS AFTER]- %d\n", countFreeCells(newGame));

    printf("R: %d - R: %d - R: %d - R: %d - R: %d - R: %d - R: %d - R: %d;\n", one, two, three, four, five, six, seven, eight);

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("[AFTER] Cell: %d, Value: %d\n", i, newGame->arena[i]);
    }
    
    // Test takeShot.
    for (int i = 0; i < BOARD_SIZE; i++) {
        int result = takeShot(newGame, i);
        printf("SHOT[%d] - Result: %d\n", i, result);
        printf("Hits: %d/Shots: %d, Score: %f\n", getHits(newGame), getShotsTaken(newGame), getScore(newGame));
    }

    // Check values via function after shot;
    printf("[FUNCTION AFTER SHOT] Shots: %d, Hits: %d, Score: %f\n", getShotsTaken(newGame), getHits(newGame), getScore(newGame));

    // Check values after shot.
    printf("[NON-FUNCTION AFTER SHOT] Shots: %d, Hits: %d, Score: %f\n", newGame->shots, newGame->hits, newGame->score);

    printf("DIVI - %f\n", (float)getHits(newGame)/BOARD_SIZE);

    // Check arena.
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("[AFTER SHOTS] Cell: %d, Value: %d\n", i, newGame->arena[i]);
    }

    // Check memory.
    if (!newGame) {
        printf("UH OH 2\n");
    }
    if (newGame) {
        printf("WE GOOD 2\n");
    }

    // Final values
    printf("Final Hits: %d, Final Shots %d, Final Score %f;\n", getHits(newGame), getShotsTaken(newGame), getScore(newGame));

    // End game.
    endGame(newGame);

    // Check memory after ending.
    if (!newGame) {
        printf("WE GOOD 3\n");
    }
    if (newGame) {
        printf("UH OH 3\n");
    }

    return 0;
}