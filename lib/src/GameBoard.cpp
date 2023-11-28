//
// Created by natha on 11/28/2023.
//

#include "../include/GameBoard.h"

GameBoard::GameBoard(int bs) {
    boardSize = bs;

    initBoard();
}

// initialize the game board
void GameBoard::initBoard() {
    // reserve space on the board
    board.reserve(boardSize);
    for (int i = 0; i < boardSize; ++i) {
        board[i].reserve(boardSize);
    }

    // fill the board with nullptrs
    for (vector<Ship*> x : board) {
        for (Ship* &y : x) {
            y = nullptr;
        }
    }
}