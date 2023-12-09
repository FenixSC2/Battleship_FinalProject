# Battleship Final Project
### Information
_This project is the final assignment for NU CS3520, developed by Alex Chen and Nathan Barth. It's a terminal-based Battleship game, offering a unique, text-based gameplay experience._

### Battleship Game Rules:
_In this version of battleship you will first be prompted to place your ships on the board._
- _Default ship placement will place a ship down/right (based on vertical or horizontal user input) of the point input by the player._
- _If there is not space to place the ship down/right of the ship but there is space up/right of the location the ship will be placed there instead._
- _If the ship cannot be placed in either direction you must input a new location._

_Once the player has placed all their ships the CPU will randomly place its ships on its board and the game will begin._

_When the game begins the player will be asked to input a location in the format "x y" within the boardsize._ 
- _If the location is not on the board the game prompts a new input._
- _If the input location is a hit on a ship the player will be notified and asked to play again._
- _If the location is a miss the player is notified and it becomes the CPU's turn (following the same rules)._

_This continues until the game ends when either the player or the CPU sinks all enemy ships._

### Visualizing the board:

_The board is displayed to the user via ASCII on the command line._
- _Empty squares are displayed as "| |"_.
- _Squares containing ships are displayed as_ "|1|", "|2|", "|3|", _etc._
  - _Each unique number indicates a unique ship, for example the horizontal ship number 1 (with size 2) would appear on the baord as:_

[ ][ ][ ][ ]

[ ][1][1][ ]

[ ][ ][ ][ ]

- _Squares that have been hit are displayed as_ "|X|".
   - _The CPU's hits are displayed on the player board._
   - _The Player's hits are displayed on an empty board._

### How to Play
#### Setup Requirements
- _Ensure that matplot++ is installed on your system._

#### Running the Game
- Open your IDE (this project was developed in CLion).
- Run main.cpp.

#### Game Configuration
- _The game settings can be adjusted by editing the BattleData.txt file._
- _You can modify parameters such as board size, the number of ships, and the sizes of the ships._

#### Default Game Settings
- _Board Size: 10x10_
- _Number of Ships: 5_
- _Ship Sizes: [2, 2, 3, 3, 4]_

### CPU Behavior
_In the game, the CPU follows a specific strategy for its moves:_

- **Initial Guessing**: _The CPU starts by guessing grid locations randomly._

- **Strategic Follow-Up**: _If the CPU scores a hit, it then focuses on the adjacent grid spaces in subsequent turns._

_When initializing its board, the CPU will generate ship locations randomly._

### Libraries Utilized
_The development of this project incorporates several external libraries, each serving a unique purpose to enrich the game experience:_

#### - _[**miniaudio**:](https://github.com/mackron/miniaudio)_

- _We used Miniaudio to add sounds to the game flow. There are 6 total sounds including background music._

#### - _[**matplotplusplus**:](https://github.com/alandefreitas/matplotplusplus)_

- _Employed for data visualizations. Stored graph visualizations as 'cpu_statistics.png'
and 'player_statistics.png'._
- _Example graph: [Graph Link](https://ibb.co/tBn8pJs)_