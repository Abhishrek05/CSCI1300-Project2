//Board.h

#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include "Player.h"

//comment showing where things are (reqs)
//2 nested loops
//6 total loops
//6 if statements
//class that has an array from another class 
//if stream and ofstream


class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    void displayTile(int,int,int player_index, int pos);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count);
    void displayTrack(bool,bool,int player_index);
    void initializeBoard();
    void displayBoard(bool,bool);
    bool movePlayer(int player_index, int steps, Player chars[2]);
    int getPlayerPosition(int player_index) const;
    void checkTileEvent(int player_index, Player chars[2]);
    int split(string input_string, char separator, string arr[], const int ARR_SIZE);
};

#endif