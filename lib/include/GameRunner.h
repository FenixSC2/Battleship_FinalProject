//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_GAMERUNNER_H
#define BATTLESHIP_FINALPROJECT_GAMERUNNER_H

#include "GameBoard.h"
#include "iostream"
#include "AudioPlayer.h"

using namespace std;

class GameRunner {
private:
    // data
    int boardSize, numShips;
    vector<int> shipSizes;
    vector<Ship*> allShips;
    // boards for the player and cpu
    GameBoard* playerBoard;
    GameBoard* cpuBoard;

    // audio players
    AudioPlayer backgroundMusicPlayer;
    AudioPlayer eventSoundPlayer;


    // for player moves
    // gets and hits the location the player would like to hit
    void getPlayerMove();

    // for computer moves
    // gets and hits the location the cpu selected to hit
    void getcpuMove();

    // hit an adjacent square to the input square in the direction provided
    void hitAdjacent(IntPair pair, int direction, int timesCalled);

    // for determining if the game has concluded
    bool isGameOver();

    // create the ships for the game to be used by the player and CPU
    void createShips();

    // create an ASCII representation of the board
    void drawASCII(GameBoard* board, vector<IntPair> guesses) const;

    // allow the player to place their ships on their board
    void placePlayerShips();
    // get a IntPair from the player
    IntPair getIntPairInputASCII(bool &isVertical);

    // keeps track of which spaces have been guessed so far by the cpu and player respectively
    vector<IntPair> cpuGuesses;
    vector<IntPair> playerGuesses;

public:
    // constructors
    GameRunner();
    GameRunner(int boardSize, int numShips, vector<int> shipSizes);

    // start and run the game
    void play();
};


#endif //BATTLESHIP_FINALPROJECT_GAMERUNNER_H
