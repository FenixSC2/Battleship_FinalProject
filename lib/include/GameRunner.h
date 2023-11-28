//
// Created by natha on 11/28/2023.
//

#ifndef BATTLESHIP_FINALPROJECT_GAMERUNNER_H
#define BATTLESHIP_FINALPROJECT_GAMERUNNER_H


class GameRunner {
private:
    // for player moves
    void playerMove();

    // for computer moves
    void cpuMove();

    // for determining if the game has concluded
    bool isGameOver();

public:
    // constructor
    GameRunner(int boardSize, int numShips, int shipSizes[numShips]);

    // start and run the game
    void play();
};


#endif //BATTLESHIP_FINALPROJECT_GAMERUNNER_H
