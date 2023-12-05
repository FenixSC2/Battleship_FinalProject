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
    // have the player place their ships
    placePlayerShips();
    // generation of locations for the CPU ships is done automatically

    // begin actual play of the game
    drawASCII(playerBoard, cpuGuesses);

    cout << "THE GAME BEGINS!!" << endl << endl;

    while(!isGameOver()) {
        getPlayerMove();
        getcpuMove();
        isGameOver();
        cout << "Your current board:" << endl;
        drawASCII(playerBoard, cpuGuesses);
        // for debug
        cout << "DEBUG::CPU current board: " << endl;
        drawASCII(cpuBoard, playerGuesses);
    }
}

void GameRunner::getPlayerMove() {
    // get an IntPair location from the player
    int x, y;
    cout << "Please enter the pair location that you would like to hit \"x y\"" << endl;
    // make sure that x and y are valid
    while (!(cin >> x >> y)) {
        cout << "Invalid input. Please enter two integers." << endl;
        cin.clear();  // Clear the fail state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
    }
    // check that 2 ints were correctly input
    if (playerBoard->onBoard(IntPair(x, y))) {
        cout << "You entered the location: " << x << ", " << y << endl;
        // temp variable keeps track of if the IntPair(x, y) is contained in the vector playerGuesses
        bool temp;
        // search for the value
        auto it = std::find(playerGuesses.begin(), playerGuesses.end(), IntPair(x, y));
        // Check if the value was found
        if (it != playerGuesses.end()) {
            temp = true;
        } else {
            temp = false;
        }
        // if the value was found get a new value
        if (temp) {
            cout << "You already input that value, please input a new value." << endl;
            getPlayerMove();
        } else {
            // determine if there was a ship at the input location
            if (cpuBoard->hit(IntPair(x, y))) {
                cout << "Hit ship at \"" << x << ", " << y << "\"" << endl;
                cout << "Go again!" << endl;
                // add this location to the vector list of hit locations
                playerGuesses.emplace_back(IntPair(x, y));
                // if the player got a hit they get to go again
                getPlayerMove();
            } else {
                cout << "You missed!" << endl;
                // add this location to the vector list of hit locations
                playerGuesses.emplace_back(IntPair(x, y));
            }
        }
    } else {
        cout << "That location is not on the board." << endl;
        // read a new location / player move
        getPlayerMove();
    }
}

void GameRunner::getcpuMove() {
    // randomly generate an IntPair for the CPU move
    IntPair pair1 = IntPair();
    pair1.setPair(rand() % boardSize, rand() % boardSize);

    // temp variable keeps track of if the IntPair(x, y) is contained in the vector cpuGuesses
    bool temp;
    // search for the value
    auto it = std::find(cpuGuesses.begin(), cpuGuesses.end(), pair1);
    // Check if the value was found
    if (it != cpuGuesses.end()) {
        temp = true;
    } else {
        temp = false;
    }
    // if the value was found get a new value
    if (temp) {
        getcpuMove();
    } else {
        // say where the cpu fired at
        cout << "CPU fired at (" << pair1.getX() << ", " << pair1.getY() << ")" << endl;
        // determine if there was a ship at the input location
        if (playerBoard->hit(pair1)) {
            cout << "CPU hit ship at \"" << pair1.getX() << ", " << pair1.getY() << "\"" << endl;
            cout << "CPU goes again!" << endl;
            // add this location to the vector list of hit locations
            cpuGuesses.emplace_back(pair1);
            // select the direction the computer will attempt to move in
            int direction = rand() % 4;
            hitAdjacent(pair1, direction, 0);
        } else {
            cout << "CPU missed!" << endl;
            // add this location to the vector list of hit locations
            cpuGuesses.emplace_back(pair1);
        }
    }
}

void GameRunner::hitAdjacent(IntPair pair, int direction, int timesCalled) {
    // if we have called enough times to try all directions get a new random position
    timesCalled++;
    if (timesCalled > 4) {
        getcpuMove();
    } else {
        // make a move based on direction
        switch (direction) {
            case 0:
                // up
                // if we are on the board
                if (playerBoard->onBoard(IntPair(pair.getX(), pair.getY() - 1))) {
                    IntPair newPair = IntPair(pair.getX(), pair.getY() - 1);
                    // say where the cpu fired at
                    cout << "CPU fired at (" << newPair.getX() << ", " << newPair.getY() << ")" << endl;
                    // if we hit a boat
                    if (playerBoard->hit(IntPair(newPair.getX(), newPair.getY()))) {
                        cout << "CPU hit ship at \"" << newPair.getX() << ", " << newPair.getY() << "\"" << endl;
                        cout << "CPU goes again!" << endl;
                        // add this location to the vector list of hit locations
                        cpuGuesses.emplace_back(newPair);
                        // select the direction the computer will attempt to move in
                        hitAdjacent(newPair, direction, timesCalled);
                    } // if we missed the boats
                    else {
                        cout << "CPU missed!" << endl;
                        // add this location to the vector list of hit locations
                        cpuGuesses.emplace_back(newPair);
                    }
                } // if we are not on the board
                else {
                    direction++;
                    hitAdjacent(pair, direction, timesCalled);
                }
            case 1:
                // right
                // if we are on the board
                if (playerBoard->onBoard(IntPair(pair.getX() + 1, pair.getY()))) {
                    IntPair newPair = IntPair(pair.getX() + 1, pair.getY());
                    // say where the cpu fired at
                    cout << "CPU fired at (" << newPair.getX() << ", " << newPair.getY() << ")" << endl;
                    // if we hit a boat
                    if (playerBoard->hit(IntPair(newPair.getX(), newPair.getY()))) {
                        cout << "CPU hit ship at \"" << newPair.getX() << ", " << newPair.getY() << "\"" << endl;
                        cout << "CPU goes again!" << endl;
                        // add this location to the vector list of hit locations
                        cpuGuesses.emplace_back(newPair);
                        // select the direction the computer will attempt to move in
                        hitAdjacent(newPair, direction, timesCalled);
                    } // if we missed the boats
                    else {
                        cout << "CPU missed!" << endl;
                        // add this location to the vector list of hit locations
                        cpuGuesses.emplace_back(newPair);
                    }
                } // if we are not on the board
                else {
                    direction++;
                    hitAdjacent(pair, direction, timesCalled);
                }
            case 2:
                // down
                // if we are on the board
                if (playerBoard->onBoard(IntPair(pair.getX(), pair.getY() + 1))) {
                    IntPair newPair = IntPair(pair.getX(), pair.getY() + 1);
                    // say where the cpu fired at
                    cout << "CPU fired at (" << newPair.getX() << ", " << newPair.getY() << ")" << endl;
                    // if we hit a boat
                    if (playerBoard->hit(IntPair(newPair.getX(), newPair.getY()))) {
                        cout << "CPU hit ship at \"" << newPair.getX() << ", " << newPair.getY() << "\"" << endl;
                        cout << "CPU goes again!" << endl;
                        // add this location to the vector list of hit locations
                        cpuGuesses.emplace_back(newPair);
                        // select the direction the computer will attempt to move in
                        hitAdjacent(newPair, direction, timesCalled);
                    } // if we missed the boats
                    else {
                        cout << "CPU missed!" << endl;
                        // add this location to the vector list of hit locations
                        cpuGuesses.emplace_back(newPair);
                    }
                } // if we are not on the board
                else {
                    direction++;
                    hitAdjacent(pair, direction, timesCalled);
                }
            default:
                // left
                // if we are on the board
                if (playerBoard->onBoard(IntPair(pair.getX() - 1, pair.getY()))) {
                    IntPair newPair = IntPair(pair.getX() - 1, pair.getY());
                    // say where the cpu fired at
                    cout << "CPU fired at (" << newPair.getX() << ", " << newPair.getY() << ")" << endl;
                    // if we hit a boat
                    if (playerBoard->hit(IntPair(newPair.getX(), newPair.getY()))) {
                        cout << "CPU hit ship at \"" << newPair.getX() << ", " << newPair.getY() << "\"" << endl;
                        cout << "CPU goes again!" << endl;
                        // add this location to the vector list of hit locations
                        cpuGuesses.emplace_back(newPair);
                        // select the direction the computer will attempt to move in
                        hitAdjacent(newPair, direction, timesCalled);
                    } // if we missed the boats
                    else {
                        cout << "CPU missed!" << endl;
                        // add this location to the vector list of hit locations
                        cpuGuesses.emplace_back(newPair);
                    }
                } // if we are not on the board
                else {
                    direction = 0;
                    hitAdjacent(pair, direction, timesCalled);
                }
        }
    }
}

bool GameRunner::isGameOver() {
    // check if the game is over for either the player or the cpu
    if (playerBoard->isOver() || cpuBoard->isOver()) {
        if (cpuBoard->isOver()) {
            //TODO win message for non terminal output
            cout << "Congratulations! \nYou Win!" << endl << endl;
        } else {
            cout << "You lost.\nBetter luck next time!" << endl << endl;
        }
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

void GameRunner::drawASCII(GameBoard* board, vector<IntPair> guesses) const {
    //cout << "Drawing the grid" << endl; // debug line
    // create top numbers
    cout << "   ";
    for (int i = 0; i < boardSize; i++) {
        cout << i << " ";
    }
    cout << endl;
    // create top border
    for (int i = 0; i < boardSize + 1; i++) {
        cout << "--";
    }
    std::cout << "-" << std::endl;
    // create rows
    for (int i = 0; i < boardSize; i++) {
        // write the row column first
        cout << i << " ";
        for (int j = 0; j < boardSize; j++) {
            std::cout << "|";
            if (board->getPos(IntPair(j, i)) == nullptr) {
                // determine if this spot was formerly occupied by a ship
                // temp variable keeps track of if the IntPair(x, y) is contained in the vector cpuGuesses
                bool temp;
                // search for the value
                auto it = std::find(guesses.begin(), guesses.end(), IntPair(j , i));
                // Check if the value was found
                if (it != guesses.end()) {
                    temp = true;
                } else {
                    temp = false;
                }
                // space for unoccupied, X for formerly occupied
                if (temp) {
                    cout << "X";
                } else {
                    cout << " ";
                }
            } else {
                std::cout << board->getPos(IntPair(j, i))->display() + 1; // + 1 so that we dont have a 0 ship
            }
        }
        std::cout << "|" << std::endl;
    }
    // create bottom border
    for (int i = 0; i < boardSize + 1; i++) {
        std::cout << "--";
    }
    std::cout << "-" << std::endl;
}

void GameRunner::placePlayerShips() {
    // get a location from the player in the form of (int, int) coordinate
    // for each ship get a position from the player
    int counter = 0;
    for (Ship* sh : allShips) {
        counter++;
        bool isVertical;
        bool rightOrDown;
        cout << "Your current board is:" << endl;
        drawASCII(playerBoard, cpuGuesses);
        cout << endl << "Please place ship number " << counter << "." << endl << endl;
        // get position and orientation from the player
        IntPair pos = getIntPairInputASCII(isVertical);
        // see if there is space at that position for the given ship
        while (!(playerBoard->shipSpace(pos, sh->getSize(), isVertical, rightOrDown))) {
            cout << "There is not space for a ship there, please enter a different location" << endl;
            pos = getIntPairInputASCII(isVertical);
        }
        // if once a valid location has been selected, place the ship at that location
        // first populate locations
        vector<IntPair> locations;
        // populate locations
        for (int i = 0; i < sh->getSize(); i++) {
            if (isVertical) {
                if (rightOrDown) {
                    locations.emplace_back(IntPair(pos.getX(), pos.getY() + i));
                } else {
                    locations.emplace_back(IntPair(pos.getX(), pos.getY() - i));
                }
            } else {
                if (rightOrDown) {
                    locations.emplace_back(IntPair(pos.getX() + i, pos.getY()));
                } else {
                    locations.emplace_back(IntPair(pos.getX() - i, pos.getY()));
                }
            }
        }
        // place the ship on the player's board at the proper locations
        playerBoard->placeShip(locations, sh);
        cout << "Placed player ship " << counter << " at (" << pos.getX() << ", " << pos.getY() << ")" << endl;
    }
}

// this currently runs in the terminal
// TODO: When GUI is implemented use the GUI to get these values with a new function + change the call in relevant locations
IntPair GameRunner::getIntPairInputASCII(bool &isVertical) {
    cout << "Would you like your ship to be vertical (input \"v\") or horizontal (input \"h\")" << endl;
    string vertString;
    cin >> vertString;
    while (vertString != "v" && vertString != "h") {
        cout << "You entered \"" << vertString << "\"" << endl;
        cout << "That is not a valid input. Please enter a valid input: " << endl;
        cin.clear(); // clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cin >> vertString;
    }
    if (vertString == "v") {
        isVertical = true;
    } else {
        isVertical = false;
    }
    cout << "Enter two separate number values \"x y\" for the coordinate you would like: " << endl;
    cout << "Your board is " << boardSize << " tiles large, so enter values between 0 and " << boardSize - 1 << endl;
    int x;
    int y;
    cin >> x >> y;
    IntPair pair1 = IntPair(x, y);
    // if the pair is not on the board get a new pair that is on the board
    if (!(playerBoard->onBoard(pair1))) {
        cout << "That value is not on the board, please enter a valid position." << endl;
        pair1 = getIntPairInputASCII(isVertical);
    }
    return pair1;
}
