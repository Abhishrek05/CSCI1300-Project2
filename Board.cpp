/*
Board.cpp Pseudocode:
1. initialize the two boards
2. create a function to initialize cub tiles
A. Set up board color order/random
B. set up the color of the tiles to corresponding actions/events
C. // Assign the tile to the board for the specified lane
3. Do a similar function for pride land tiles
4. Make the position available to track
Initialize player position
check if player is on the tile
initialize the tiles and make them display their traits
ready the display board function
make the player move function
store player position
 */




/*
Normal tiles(green) - 50% of random even happening (randomevent.txt)

• Oasis Tile (blue color tile): You’ve found a peaceful oasis! This grants the player an extra turn to keep
moving forward—take a deep breath and relax; you also gain 200 Stamina, Strength, and Wisdom
Points.
• Counseling Tile (pink color tile): Welcome to the land of enrichment - when landing on this tile, your
Stamina, Strength, and Wisdom Points increase by 300, and you get to choose an advisor from the
available list of advisors. If you already have an advisor, you can switch your advisor out for a different
one from the list or keep your original advisor. Don’t forget - an advisor can protect you from random
events that negatively impact your Pride Points.
• Graveyard Tile (red color tile): Uh-oh, you’ve stumbled into the Graveyard! This forces the player to
move back 10 tiles and lose 100 Stamina, Strength, and Wisdom Points.
• Hyenas Tile (brown color tile): The Hyenas are on the prowl! They drag you back to where you were
last, and the journey comes at a cost. This returns the player to their previous position. In addition,
the player’s Stamina Points decrease by 300 Points.
• Challenge Tile (purple color tile): Time for a test of wits! Land here, and you’ll face a riddle randomly
pulled from the riddles.txt file. Answer correctly, and you’ll earn a boost of 500 Points to your
Wisdom Trait—your cleverness pays off!

*/






#include "Board.h"
#include <iostream>

using namespace std;

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i);  // This ensures each lane has a unique tile distribution
    }
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void Board::initializeTiles(int player_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        } 
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 100;
            // switch (color_choice)
            // {
            //     case 0:
            //         temp.color = 'B'; // Blue
            //         break;
            //     case 1:
            //         temp.color = 'P'; // Pink
            //         break;
            //     case 2:
            //         temp.color = 'N'; // Brown
            //         break;
            //     case 3:
            //         temp.color = 'R'; // Red
            //         break;
            //     case 4:
            //         temp.color = 'U'; // Purple
            //         break;
            // }
            if(player_index == 0) { //first half (Pride Lands)
                if(color_choice < 25) {
                    temp.color = 'R'; //graveyard
                } else if (color_choice > 25 && color_choice <= 50) {
                    temp.color = 'N'; //hyenas
                } else if (color_choice > 50 && color_choice <=70) {
                    temp.color = 'P';
                } else if (color_choice > 70 && color_choice <=95) {
                    temp.color = 'U';
                } else if (color_choice > 95) {
                    temp.color = 'B';
                }
            } else if(player_index == 1) { //second half (Advisor Path)
                if(color_choice < 25) {
                    temp.color = 'R'; //graveyard
                } else if(color_choice > 15 && color_choice <=30) {
                    temp.color = 'N';
                } else if(color_choice > 30 && color_choice <= 50) {
                    temp.color = 'P';
                } else if(color_choice > 50 && color_choice <= 75) {
                    temp.color = 'U';
                } else if(color_choice > 75) {
                    temp.color = 'B';
                }
            }
        }

        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}


Board::Board()
{
    _player_count = 1;

    // Initialize player position
    _player_position[0] = 0;

    // Initialize tiles
    initializeTiles(1);
}

Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }

    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // Initialize tiles

    initializeBoard();
}

bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}

void Board::displayTile(int player_index, int pos)
{
    // string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

    // Determine color to display
    if (_tiles[player_index][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[player_index][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[player_index][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[player_index][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[player_index][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[player_index][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[player_index][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[player_index][pos].color == 'Y')
    {
        color = GREY;
    }

     if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i);
    }
    cout << endl;
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0) {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index, int steps)
{
    // Increment player position
    _player_position[player_index] += steps;

    

    if (_player_position[player_index] >= _BOARD_SIZE - 1)
    {
        // Player reached last tile
        _player_position[player_index] = 51;
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}