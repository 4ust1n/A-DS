#include "lab4.h"

int main() {
    puts("----------------RUNNING TESTS----------------");
    GameBoard *board = newBoard();

    placeShip(board, 0);
    placeShip(board, BOARD_SIZE - 1);
    placeShip(board, BOARD_SIZE / 2);

    if(board->arena[0] != 1) {
        puts("ERROR: placeShip did not update cell");
    }
    if(board->arena[BOARD_SIZE - 1] != 1) {
        puts("ERROR: placeShip did not update cell");
    }
    if(board->arena[BOARD_SIZE / 2] != 1) {
        puts("ERROR: placeShip did not update cell");
    }

    if(getShotsTaken(board) != 0) {
        puts("ERROR: nonzero default for shots taken");
    }
    if(getHits(board) != 0) {
        puts("ERROR: nonzero default for hits");
    }
    if(getScore(board) != 0) {
        puts("ERROR: nonzero default for score");
    }

    int ships = countRemainingShips(board);
    if(ships != 3) {
        printf("ERROR: remaining ships, expected %d, got %d\n", 3, ships);
    }

    int result = takeShot(board, 5);
    if(result != 0) {
        printf("ERROR: takeShot returned %d, expected %d\n", result, 0);
    }

    if(getShotsTaken(board) != 1) {
        puts("ERROR: unexpected shots taken");
    }
    if(getHits(board) != 0) {
        puts("ERROR: hits unexpectedly nonzero");
    }
    float score = getScore(board);
    if(score != 0.0) {
        puts("ERROR: unexpected score");
    }

    ships = countRemainingShips(board);
    if(ships != 3) {
        printf("ERROR: remaining ships, expected %d, got %d\n", 3, ships);
    }

    result = takeShot(board, 0);
    if(result != 1) {
        printf("ERROR: takeShot returned %d, expected %d\n", result, 1);
    }

    if(getShotsTaken(board) != 2) {
        puts("ERROR: unexpected shots taken");
    }
    if(getHits(board) != 1) {
        puts("ERROR: hits returned unexpected value");
    }
    score = getScore(board);
    if(score != (1.0 / 2.0)) {
        puts("ERROR: unexpected score");
    }

    ships = countRemainingShips(board);
    if(ships != 2) {
        printf("ERROR: remaining ships, expected %d, got %d\n", 2, ships);
    }


    puts("----------------FREEING ARRAY----------------");

    endGame(board);
}

