#include "lab4.h"

/*
Create a new game

Returns:
A new board via malloc of type Gameboard as defined in the header file struct.
*/
GameBoard * newBoard() {

    GameBoard *board;

    board = malloc(sizeof(GameBoard));

    if (!board) {
        return NULL;
    }

    board->shots = 0;
    board->hits = 0;
    board->score = 0.0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        board->arena[i] = 0;
    }

    return board; 
}

/*
A game action that attempts to shoot a ship if found at a certain cell.

Parameters:
Gameboard *board - Pointer to a game board.
int cell - The specific index of the board to check for a ship.

Returns:
1 if shot was successsful in shooting a ship, otherwise 0.
*/
int takeShot(GameBoard *board, int cell) {

    // Add to shots.
    board->shots += 1;

    if (board->arena[cell] == 0 || board->arena[cell] == -1) {

        // Update score on failure.
        board->score = (float)getHits(board) / getShotsTaken(board);

        return 0;
    }

    // Set cell to destroyed.
    board->arena[cell] = -1;

    // Add to hits
    board->hits += 1;

    // Update score on success.
    board->score = (float)getHits(board) / getShotsTaken(board);

    return 1;
}

/*
Check how many cells are without ships (empty).

Parameter:
Gameboard *board - Pointer to game board.

Returns:
The amount of cells without ships (empty).
*/
int countFreeCells(GameBoard *board) {

    int *arena, count = 0;

    arena = board->arena;

    for (int cell = 0; cell < BOARD_SIZE; cell++) {
        if (arena[cell] == 0) {
            count++;
        }
    }

    return count;
}

/*
Get the total amount of shots taken so far in the game.

Parameter:
Gameboard *board - Pointer to game board that is of type Gameboard

Returns:
The total amout of shots.
*/
int getShotsTaken(GameBoard *board) {
    return board->shots;
}


/*
Gets the total amount of successful hits so far in the game.

Parameters:
Gameboar *board - Pointer to game board.

Returns:
The total amount of hits.
*/
int getHits(GameBoard *board) {
    return board->hits;
}

/*
Gets the current score.

Parameter:
Gamebaord *board - Pointer to the game board that is of type Gameboard.

Returns:
The score.
*/
float getScore(GameBoard *board) {
    return board->score;
}

/*
Places a ship onto the game board.

Parameters:
Gameboard *board - Pointer to the game board.
int cell - The specific cell of the arena that user wants to place ship on, if available.

Returns:
1 if ship was successfully placed on cell, otherwise 0.
*/
int placeShip(GameBoard *board, int cell) {

    int *arena = board->arena;
    
    if (arena[cell] == 1 || arena[cell] == -1) {
        return 0;
    }

    arena[cell] = 1;

    return 1;

}

/*
Ends the game by freeing the memory.

Parameter:
Gameboard *board - Pointer to game board that is of type Gameboard.
*/
void endGame(GameBoard *board) {
    free(board);
    board = NULL;
}