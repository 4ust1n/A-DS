#include "lab3.h"

/* newBoard
    This function creates and returns a
    new, empty game board. It will return
    a pointer to the board on success, or
    NULL on failure.
*/
int * newBoard() {
    // Our memory layout is: | score | hits | shots | user space |
    float *array = malloc((BOARD_SIZE + 2) * sizeof(int) + sizeof(float));

    if(!array) {
        return NULL;
    }

    *array = 0.0;

    /*
        We must move the array pointer past the first float space,
        since we cannot guarantee that sizeof(int) == sizeof(float)
        on every platform.
    */
    int *board = (int *)(array + 1);
    for(int i = 0; i < BOARD_SIZE + 2; ++i) {
        board[i] = 0;
    }

    return board + 2;
}

/* takeShot
    This function takes a board, as well
    as a cell number to shoot at. It will
    check the status of the given cell,
    and return 1 if it hit a target, or
    0 if the cell was either empty or
    destroyed.

    Param: int *board;  The board in play
    Param: int cell;    The cell to shoot at
*/
int takeShot(int *board, int cell) {
    int status = board[cell];
    board[-1]++;

    if(status == 1) {
        board[-2]++;
        board[cell] = -1;
    }

    updateScore(board);
    return status == 1;
}

/* countFreeCells
    This function takes a board, and
    returns the number of empty cells
    on it.

    Param: int *board;  The board in play
*/
int countFreeCells(int *board) {
    int count = 0;
    for(int i = 0; i < BOARD_SIZE; ++i) {
        if(board[i] == 0) {
            ++count;
        }
    }

    return count;
}

/* getShotsTaken
    This function takes a board, and
    returns the number of shots the
    player has taken on it.

    Param: int *board;  The board in play
*/
int getShotsTaken(int *board) {
    return board[-1];
}

/* getHits
    This function takes a board, and
    returns the number of hits the
    player has landed on it.

    Param: int *board;  The board in play
*/
int getHits(int *board) {
    return board[-2];
}

/* getScore
    This function takes a board, and
    returns the ratio of hits to shots
    so far on the board.

    Param: int *board;  The board in play
*/
float getScore(int *board) {
    board -= 2;
    float *array = (float *)board;
    return array[-1];
}

/* updateScore
    This function takes a board, and
    updates the ratio of hits to shots
    so far on the board.

    Param: int *board;  The board in play
*/
void updateScore(int *board) {
    float hits = getHits(board);
    float shots = getShotsTaken(board);

    board -= 2;
    float *array = (float *)board;
    array[-1] = hits / shots;
}

/* endGame
    This function takes a board, and
    frees all memory allocated to it.

    Param: int *board;  The board to free
*/
void endGame(int *board) {
    board -= 2;
    float *array = (float *)board;
    free(array - 1);
}