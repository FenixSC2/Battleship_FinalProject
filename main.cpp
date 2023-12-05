#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>
#include "lib/include/GameRunner.h"

int main(int argc, char* argv[]) {
    // info to be read from file
    int boardSize = 0;
    int numShips = 0;
    std::vector<int> shipSizes;

    // check the number of command line args
    if (argc < 2) {
        std::cerr << "No file provided via command line" << std::endl;
        return 1; // return an error code
    }

    // Open the file specified in the command line argument
    std::ifstream inputFile(argv[1]);
    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file: " << argv[1] << std::endl;
        return 1; // Return an error code
    }

    std::string token;
    while (inputFile >> token) {
        std::istringstream iss(token);
        int value;
        if (iss >> value) {
            // Successfully read an integer, add it to the appropriate variable
            if (boardSize == 0) {
                boardSize = value;
            } else if (numShips == 0) {
                numShips = value;
            } else {
                shipSizes.emplace_back(value);
            }
        }
    }

    // Close the file
    inputFile.close();

    /*
     * Now that we have all the data, all that is needed is to run the game:
     */
    std::cout << "Board size: " << boardSize << std::endl;
    std::cout << "Number of ships: " << numShips << std::endl;
    std::cout << "Ship sizes (ships will be placed in this order L->R): ";
    for (int size : shipSizes) {
        std::cout << size << " ";
    }
    std::cout << std::endl;

    GameRunner* runner = new GameRunner(boardSize, numShips, shipSizes);

    runner->play();

    std::cout << std::endl << "Thanks for playing!" << std::endl;

    return 0;
}
