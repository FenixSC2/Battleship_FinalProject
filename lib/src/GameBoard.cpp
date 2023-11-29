//
// Created by natha on 11/28/2023.
//

#include "../include/GameBoard.h"

GameBoard::GameBoard() {

}

GameBoard::GameBoard(int bs, vector<Ship> s, bool placedRandomly) {
    boardSize = bs;
    ships = s;

    if (placedRandomly) {
        setSail();
    }

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

void GameBoard::setSail() {
    // TODO: for setting location of cpu ships when the game starts
}

GameBoard::GameBoard(const GameBoard &other) {
    // Copy the board size
    boardSize = other.boardSize;

    // Deep copy the ships vector
    ships = other.ships;

    // Initialize the board
    initBoard();

    // Copy the content of the board
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            // Check if the cell in 'other' has a ship
            if (other.board[i][j] != nullptr) {
                // Create a new ship with the same type
                board[i][j] = new Ship(*(other.board[i][j]));
            }
        }
    }
}

GameBoard &GameBoard::operator=(const GameBoard &other) {
    if (this != &other) { // Check for self-assignment
        // Release resources of the current object
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                delete board[i][j];
            }
        }

        // Copy the board size
        boardSize = other.boardSize;

        // Deep copy the ships vector
        ships = other.ships;

        // Initialize the board
        initBoard();

        // Copy the content of the board
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize; ++j) {
                // Check if the cell in 'other' has a ship
                if (other.board[i][j] != nullptr) {
                    // Create a new ship with the same type
                    board[i][j] = new Ship(*(other.board[i][j]));
                }
            }
        }
    }
    return *this;
}

GameBoard::~GameBoard() {
    // Release resources of the board
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            delete board[i][j];
        }
    }
}

bool GameBoard::isOver() {
    bool gate = true;
    for (Ship sh : ships) {
        gate = gate && sh.isSunk();
    }
    return gate;
}

Ship *GameBoard::getPos(IntPair pair) {
    return board[pair.getX()][pair.getY()];
}
