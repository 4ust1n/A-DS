#include "lab3.h"

int main() {
    puts("----------------RUNNING TESTS----------------");
    int *board = newBoard();

    board[0] = 1;
    board[BOARD_SIZE - 1] = 1;
    board[BOARD_SIZE / 2] = 1;

    if(getShotsTaken(board) != 0) {
        puts("ERROR: nonzero default for shots taken\n");
    }
    if(getHits(board) != 0) {
        puts("ERROR: nonzero default for hits\n");
    }
    if(getScore(board) != 0) {
        puts("ERROR: nonzero default for score\n");
    }

    int ships = countRemainingShips(board);
    if(ships != 3) {
        printf("ERRPR: remaining ships, expected %d, got %d\n", 3, ships);
    }

    int result = takeShot(board, 5);
    if(result != 0) {
        printf("ERROR: takeShot returned %d, expected %d\n", result, 0);
    }

    if(getShotsTaken(board) != 1) {
        puts("ERROR: unexpected shots taken\n");
    }
    if(getHits(board) != 0) {
        puts("ERROR: hits unexpectedly nonzero\n");
    }
    float score = getScore(board);
    if(score != 0.0) {
        puts("ERROR: unexpected score\n");
    }

    ships = countRemainingShips(board);
    if(ships != 3) {
        printf("ERRPR: remaining ships, expected %d, got %d\n", 3, ships);
    }

    result = takeShot(board, 0);
    if(result != 1) {
        printf("ERROR: takeShot returned %d, expected %d\n", result, 1);
    }

    if(getShotsTaken(board) != 2) {
        puts("ERROR: unexpected shots taken\n");
    }
    if(getHits(board) != 1) {
        puts("ERROR: hits returned unexpected value\n");
    }
    score = getScore(board);
    if(score != (1.0 / 2.0)) {
        puts("ERROR: unexpected score\n");
    }

    ships = countRemainingShips(board);
    if(ships != 2) {
        printf("ERRPR: remaining ships, expected %d, got %d\n", 2, ships);
    }


    puts("----------------FREEING ARRAY----------------");

    endGame(board);
}

