#include "lab3.h"

/*
    Creates a new array that represents a 1D game of Battleship.

    Index 0 represents shots taken, while index 1 represents successful hits,
    and index 2 represents the score.

    Returns:
    If memory allocated failed, returns NULL. Otherwise, an array allocated of size BOARD_SIZE + 3 that 
    represents the game board with default values of 0 (empty). 
*/
int * newBoard() {

    int *board = malloc((BOARD_SIZE + 3) * sizeof(int));

    if (board == NULL) {
        return NULL;
    }

    // Initialize every cell to empty.
    for (int i = 0; i < BOARD_SIZE + 3; i++) {
        board[i] = 0;
    }

    // Set the pointer at index 2 to point to a float value
    float *scorePtr = (float *)&board[2];
    *scorePtr = 0.0f; // Initialize the float value to 0.0

    return board;
}

/*
    Action that checks if shot is either a hit or miss.

    Parameters:
    int *board - Pointer to board array.
    int cell - The specific index (cell) of the array that is to 
    be shot.

    Returns:
    1 if hit was successful, otherwise 0 as a miss.
*/
int takeShot(int *board, int cell) {

    // Add to shots taken.
    board[0] = getShotsTaken(board) + 1;

    // Shot hit ship
    if (board[cell] == 1) {

        // Destoryed Ship
        board[cell] = -1;

        // Add hit to total hits.
        board[1] = getHits(board) + 1;

        // Update the score.
        updateScore(board);

        return 1;
    } else {
        // Update the score.
        updateScore(board);
    }

    return 0;

}

/*
    Takes in the board (array) and checks for how many
    ships remain in the game.

    Parameter:
    int *board - Pointer to board array.

    Returns:
    The amount of ships, if any, remaining.
*/
int countRemainingShips(int *board) {

    int remainingShips = 0;

    for (int i = 3; i < BOARD_SIZE + 3; i++) {
        if (board[i] == 1) {
            remainingShips = remainingShips + 1;
        }
    }

    return remainingShips;
}

/*
    Gets the total amout of shots taken.

    Parameter:
    int *board - Pointer to board array.

    Returns:
    The amount of shots taken so far in the game.
*/
int getShotsTaken(int *board) {
    return board[0];
}

/*
    Gets the total amout of successful shots, which are hits.

    Parameter:
    int *board - Pointer to board array.

    Returns:
    The amount of successful shots that resulted in hits.
*/
int getHits(int *board) {
    return board[1];
}

/*
    Gets the current score of the game.

    Parameter:
    int *board - Pointer to board array.

    Returns:
    The current score of the game.
*/
float getScore(int *board) {
    return board[2];
}

/*
    Action that updates the score of the game. 
    It divides the total amount of hits by the total amount of shots taken.

    Parameter:
    int *board - Pointer to board array.
*/
void updateScore(int *board) {
    board[2] = (float)(getHits(board) / getShotsTaken(board));
}

/*
    Ends the game by freeing the memory.

    Parameter:
    int *board - Pointer to the board array.
*/
void endGame(int *board) {
    free(board);
}