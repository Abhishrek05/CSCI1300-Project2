// main.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Board.h"
#include "Game.h"


// TODO: Sorting Algo Implementation 
// TODO: Secondary layers to main menue (review advisor - avisor ability, checkplayerprogess - leadership traits to pride points)
//end of game convert all stats to pride points 
// counseling tile (re-choose advisor)



using namespace std;

int main() {

    Board board(2);
    Player players[2];
    Game game(players, board, 0);
    game.run();

    return 0;
}