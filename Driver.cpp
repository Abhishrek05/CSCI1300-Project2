#include <iostream>
#include "Board.cpp"
#include "Board.h"

using namespace std;

int main() {
    srand(time(0)); //seed random number genrator
    Board board(2);
   // board.initializeBoard();
    board.displayBoard();
    return 0;
}