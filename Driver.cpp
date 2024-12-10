// main.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Player.h"
#include "Board.h"
#include "Game.h"


// TODO: Sorting Algo Implementation 


using namespace std;

int main() {

    Board board(2);
    Player players[2];
    Game game(players, board, 0);
    game.run();

    return 0;
}