#include "lab3.h"

int main() {

    int *gameBoard = newBoard();

    for (int i = 3; i < BOARD_SIZE + 3; i++) {
        if (i % 2 == 0 && i > 12 && i < 25) {
            gameBoard[i] = 1;
        }
        printf("Index: [%d] %d\n", i, gameBoard[i]);
    }

    int shot = takeShot(gameBoard, 20);
    int shot2 = takeShot(gameBoard, 19);
    int shot3 = takeShot(gameBoard, 14);
    int shot4 = takeShot(gameBoard, 22);


    for (int i = 3; i < BOARD_SIZE + 3; i++) {
        printf("Cell: [%d] %d\n", i, gameBoard[i]);
    }

    if (shot == 1) {
         printf("[ACTION1] HIT! %d\n", shot);
    } else if (shot == 0 || shot == -1) {
        printf("[ACTION1] Miss :( %d\n", shot);
    } else {
        printf("[ACTION1] WHATT? %d\n", shot);
    }

    if (shot2 == 1) {
         printf("[ACTION2] HIT! %d\n", shot);
    } else if (shot2 == 0 || shot2 == -1) {
        printf("[ACTION2] Miss :( %d\n", shot);
    } else {
        printf("[ACTION2] WHATT? %d\n", shot);
    }

    if (shot3 == 1) {
         printf("[ACTION3] HIT! %d\n", shot);
    } else if (shot3 == 0 || shot3 == -1) {
        printf("[ACTION3] Miss :( %d\n", shot);
    } else {
        printf("[ACTION3] WHATT? %d\n", shot);
    }
    if (shot4 == 1) {
         printf("[ACTION3] HIT! %d\n", shot);
    } else if (shot4 == 0 || shot4 == -1) {
        printf("[ACTION4] Miss :( %d\n", shot);
    } else {
        printf("[ACTION4] WHATT? %d\n", shot);
    }

    printf("Shots Taken: %d\n", getShotsTaken(gameBoard));
    printf("Hits: %d\n", getHits(gameBoard));
    printf("Score: %f\n", getScore(gameBoard));
    printf("Remaining Ships: %d\n", countRemainingShips(gameBoard));

    endGame(gameBoard);


    return 0;
}