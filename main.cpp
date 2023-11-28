#include <iostream>
#include "fstream"
#include "lib/include/GameRunner.h"

int main(int argc, char* argv[]) {
    // info to be read from file
    int boardSize;
    int numShips;
    // shipSizes[] is initialized later with numShips size

    // check the number of command line args
    if (argc < 2) {
        std::cerr << "No file provided via command line" << std::endl;
        return 1; // return an error code
    }

    // read the data

    // Open the file specified in the command line argument
    std::ifstream inputFile(argv[1]);
    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file: " << argv[1] << std::endl;
        return 1; // Return an error code
    }
    // Read the size of the board
    if (!(inputFile >> boardSize)) {
        std::cerr << "Could not read board size" << std::endl;
        return 1; // Return an error code
    }
    // Read the number of ships
    if (!(inputFile >> numShips)) {
        std::cerr << "Could not read the number of ships" << std::endl;
        return 1; // Return an error code
    }

    // initialize shipSizes now that numShips is defined
    int shipSizes[numShips];

    // populate shipSizes with actual values
    for (int i = 0; i < numShips; i++) {
        int value;
        if (inputFile >> value) {
            shipSizes[i] = value;
        } else {
            std::cerr << "Error reading integer from file." << std::endl;
            return 1; // Return an error code
        }
    }

    // Close the file
    inputFile.close();

    /*
     * Now that we have all the data all that is needed is to run the game:
     */

    GameRunner runner = new GameRunner(boardSize, numShips, shipSizes);

    runner.play();

    return 0;
}
