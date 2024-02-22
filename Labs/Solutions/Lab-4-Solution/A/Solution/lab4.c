#include "lab4.h"

/* newBoard
    This function creates and returns a
    new, empty game board. It will return
    a pointer to the board on success, or
    NULL on failure.
*/
GameBoard * newBoard() {
    GameBoard *board = malloc(sizeof(GameBoard));

    if(!board) {
        return NULL;
    }

    board->hits = 0;
    board->score = 0.0;
    board->shots = 0;

    for(int i = 0; i < BOARD_SIZE; ++i) {
        board->arena[i] = 0;
    }

    return board;
}

/* takeShot
    This function takes a board, as well
    as a cell number to shoot at. It will
    check the status of the given cell,
    and return 1 if it hit a target, or
    0 if the cell was either empty or
    destroyed.

    Param: GameBoard *board;  The board in play
    Param: int cell;    The cell to shoot at
*/
int takeShot(GameBoard *board, int cell) {
    board->shots++;

    int wasHit = 0;
    if(board->arena[cell] == 1) {
        board->arena[cell] = -1;
        board->hits++;
        wasHit = 1;
    }

    board->score = (float)board->hits / (float)board->shots;
    return wasHit;
}

/* countFreeCells
    This function takes a board, and
    returns the number of empty cells
    on it.

    Param: GameBoard *board;  The board in play
*/
int countFreeCells(GameBoard *board) {
    int count = 0;
    for(int i = 0; i < BOARD_SIZE; ++i) {
        if(board->arena[i] == 0) {
            ++count;
        }
    }

    return count;
}

/* getShotsTaken
    This function takes a board, and
    returns the number of shots the
    player has taken on it.

    Param: GameBoard *board;  The board in play
*/
int getShotsTaken(GameBoard *board) {
    return board->shots;
}

/* getHits
    This function takes a board, and
    returns the number of hits the
    player has landed on it.

    Param: GameBoard *board;  The board in play
*/
int getHits(GameBoard *board) {
    return board->hits;
}

/* getScore
    This function takes a board, and
    returns the ratio of hits to shots
    so far on the board.

    Param: GameBoard *board;  The board in play
*/
float getScore(GameBoard *board) {
    return board->score;
}

/* placeShip
    This function takes a board, as well
    as a cell number to place ship. It will
    check the status of the given cell,
    and return 1 if it places a ship successfully, or
    0 if the cell isn't empty.

    Param: GameBoard *board;  The board in play
    Param: int cell;    The cell to place ship
*/
int placeShip(GameBoard *board, int cell) {
    if(board->arena[cell] != 0) {
        return 0;
    }

    board->arena[cell] = 1;
    return 1;
}

/* endGame
    This function takes a board, and
    frees all memory allocated to it.

    Param: GameBoard *board;  The board to free
*/
void endGame(GameBoard *board) {
    free(board);
}

