//
// Created by natha on 11/28/2023.
//

#include "../include/GameRunner.h"

GameRunner::GameRunner() {

}

GameRunner::GameRunner(int bs, int ns, vector<int> ss) {
    // initialize data
    boardSize = bs;
    numShips = ns;
    for (int i = 0; i < ns; i++) {
        shipSizes.emplace_back(ss[i]);
    }

    createShips();

    playerBoard = new GameBoard(boardSize, allShips, false);
    cpuBoard = new GameBoard(boardSize, allShips, true);
}

// play the game loop until the game is over
void GameRunner::play() {
    // set up the game TODO
    // have the player place their ships
    placePlayerShips();
    // generation of locations for the CPU ships is done automatically

    // begin actual play of the game
    drawASCII(cpuBoard);
//    while(!isGameOver()) {
//        getPlayerMove();
//        getcpuMove();
//    }
}

IntPair GameRunner::getPlayerMove() {

}

IntPair GameRunner::getcpuMove() {

}

bool GameRunner::isGameOver() {
    // check if the game is over for either the player or the cpu
    if (playerBoard->isOver() || cpuBoard->isOver()) {
        return true;
    }
    return false;
}

void GameRunner::createShips() {
    int count = 0;
    for (int size : shipSizes) {
        allShips.emplace_back(new Ship(count, size));
        count++;
    }
}

void GameRunner::drawASCII(GameBoard* board) const {
    cout << "Drawing the grid" << endl;
    // create top border
    for (int i = 0; i < boardSize; i++) {
        cout << "--";
    }
    std::cout << "-" << std::endl;
    // create rows
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            std::cout << "|";
            if (board->getPos(IntPair(i, j)) == nullptr) {
                std::cout << " ";
            } else {
                std::cout << board->getPos(IntPair(i, j))->display();
            }
        }
        std::cout << "|" << std::endl;
    }
    // create bottom border
    for (int i = 0; i < boardSize; i++) {
        std::cout << "--";
    }
    std::cout << "-" << std::endl;
}

void GameRunner::placePlayerShips() {
    // get a location from the player in the form of (int, int) coordinate
    // for each ship get a position from the player
    for (Ship* sh : allShips) {
        bool isVertical;
        bool leftOrUp;
        // get position and orientation from the player
        IntPair pos = getIntPairInput(isVertical);
        // see if there is space at that position for the given ship
        while (!(playerBoard->shipSpace(pos, sh->getSize(), isVertical, leftOrUp))) {
            cout << "There is not space for a ship there, please enter a different location" << endl;
            pos = getIntPairInput(isVertical);
        }
        // if once a valid location has been selected, place the ship at that location
        // first populate locations
        vector<IntPair> locations;
        // populate locations
        for (int i = 0; i < sh->getSize(); i++) {
            if (isVertical) {
                if (leftOrUp) {
                    locations.emplace_back(IntPair(pos.getX(), pos.getY() - i));
                } else {
                    locations.emplace_back(IntPair(pos.getX(), pos.getY() + i));
                }
            } else {
                if (leftOrUp) {
                    locations.emplace_back(IntPair(pos.getX() - i, pos.getY()));
                } else {
                    locations.emplace_back(IntPair(pos.getX() + i, pos.getY()));
                }
            }
        }
        // place the ship on the player's board at the proper locations
        playerBoard->placeShip(locations, sh);
    }
}

// this currently runs in the terminal
// TODO: When GUI is implemented use the GUI to get these values
IntPair GameRunner::getIntPairInput(bool &isVertical) {
    cout << "Would you like your ship to be vertical (input \"v\") or horizontal (input \"h\")" << endl;
    string vertString;
    cin >> vertString;
    while (vertString != "v" || vertString != "h") {
        cout << "You entered \"" << vertString << "\"" << endl;
        cout << "That is not a valid input. Please enter a valid input: " << endl;
        cin >> vertString;
    }
    if (vertString == "v") {
        isVertical = true;
    } else {
        isVertical = false;
    }
    cout << "Enter two separate number values (x, y) the coordinate you would like: " << endl;
    int x;
    int y;
    cin >> x >> y;
    IntPair pair1 = IntPair(x, y);
    // if the pair is not on the board get a new pair that is on the board
    if (!(playerBoard->onBoard(pair1))) {
        cout << "That value is not on the board, please enter a valid position." << endl;
        pair1 = getIntPairInput(isVertical);
    }
    return pair1;
}
