/*
Driver.cpp Pseudocode:
1. Sort through the data in the in the text files
2. Make a split function
3. Make a dice function
4.sort through riddles in the riddles.txt file
5. Put everything in main and prompt users to answer questions and play the game
6. Filter through player input from the choices in the main menu
*/
#include <iostream>
#include "Board.h"

using namespace std;


void printMainMenue(){
    cout << "Main Menu: Select an option to continue\n " << 
    "1. Check Player Progress (1)\n" <<
    "2. Review Character (2)\n" <<
    "3. Check Position (3)\n " <<
    "4. Review your Advisor (4)\n " <<
    "5. Move Forward (5)\n" <<
    "Please choose an option using the corresponding number:\n";
}


int main() {
    srand(time(0)); //seed random number genrator
    Board board(2);
   // board.initializeBoard();
    board.displayBoard();
    return 0;
}