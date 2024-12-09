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

#include "Board.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

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


void Board::initializeTiles(int rowNum)
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
           
            if(rowNum == 0) { //first half (Pride Lands)
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
            } else if(rowNum == 1) { //second half (Advisor Path)
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
        _tiles[rowNum][i] = temp;
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

void Board::displayTile(int player1path, int player2path, int rowNum, int pos)
{
    // string space = "                                       ";
    string color = "";
    int player1 = isPlayerOnTile(0, pos);
    int player2 = isPlayerOnTile(1, pos);
    //int player = isPlayerOnTile(rowNum, pos);

    // Determine color to display
    if (_tiles[rowNum][pos].color == 'R')
    {
        
        color = RED;
    }
    else if (_tiles[rowNum][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[rowNum][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[rowNum][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[rowNum][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[rowNum][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[rowNum][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[rowNum][pos].color == 'Y')
    {
        color = GREY;
    }


    if((player1path == rowNum && player2path == rowNum)) { 
       if(player1 == true && player2 == true) {
           cout << color << "|" << 1 << "&" << 2 << "|" << RESET;
       } else if(player1 == true && player2 != true) {
           cout << color << "|" << 1 << "|" << RESET;
       } else if(player1 != true && player2 == true) {
           cout << color << "|" << 2 << "|" << RESET;
       } else {
           cout << color << "| |" << RESET;
       }
    } else {
        if(player1path == rowNum) {
            if(player1 == true) {
                cout << color << "|" << 1 << "|" << RESET;
            } else {
                cout << color << "| |" << RESET;
            }
        } else if (player2path == rowNum) {
            if(player2 == true) {
                cout << color << "|" << 2 << "|" << RESET;
            } else {
                cout << color << "| |" << RESET;
            }
        }
    }
}

void Board::displayTrack(bool player1path, bool player2path, int player_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player1path, player2path, player_index, i);
    }
    cout << endl;
}

void Board::displayBoard(bool player1path, bool player2path)
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(player1path, player2path, i);
        if (i == 0) {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}



int Board::split(string input_string, char separator, string arr[], const int ARR_SIZE) {
    int count = 0;
    string temp = "";

    if (input_string.length() == 0) {
            return 0; 
        }

     for (unsigned int i = 0; i < input_string.length(); i++) {
        if (input_string[i] == separator) {
            if (count < ARR_SIZE) {
                arr[count] = temp;
                count++;
            } else {

                return -1;
            }
            temp = ""; 
        } else {
            temp += input_string[i]; 
        }
    }

    if (count < ARR_SIZE) {
        arr[count] = temp;
        count++;
    } else {
        return -1;
    }


    if (count == 1 && arr[0] == input_string) {
        return 1;
    }

    return count; 
}



bool Board::movePlayer(int player_index, int steps, Player chars[2])
{
    // Increment player position
    _player_position[player_index] += steps;

    

    if (_player_position[player_index] >= _BOARD_SIZE - 1)
    {
        // Player reached last tile
        _player_position[player_index] = 51;
        return true;
    }
    checkTileEvent(player_index, chars);
    return false;
}

void Board::checkTileEvent(int player_index, Player chars[2]) {
    int pos = _player_position[player_index];
    Tile tile = _tiles[player_index][pos];

    if (tile.color == 'G') {
        ifstream randomFile("random.txt");  // Open the file with the questions and answers
        if (!randomFile) {
            cout << "Could not open the file!" << endl;
        }

        string line;  // Maximum number of questions you want to store
        string descripton[7];
        string pathType[7];
        string advisor[7];
        string points[7];
        int count = 0;

        while (getline(randomFile, line) && count < 8) {
            string parts[4];  // Array to store the question and answer parts

            int splitCount = split(line, '|', parts, 4);

            if (splitCount == 4) {
                descripton[count] = parts[0];  // First part is the question
                pathType[count] = parts[1];    // Second part is the answer
                advisor[count] = parts[2];
                points[count] = parts[3];
                count++;
            } else if (splitCount == -1) {
                cout << "Error: Line exceeded maximum splits." << endl;
            } else if (splitCount == 0) {
                cout << "Error: Empty line encountered." << endl;
            }
        }

        randomFile.close();

        string advisorArray[6] = {"", "Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"};

        int rando = rand() % 100;
        int randomIndex = rand() % 6 + 1;
        if(rando > 50) {
            cout<<"You have triggered a random event."<<endl;
            if(chars[player_index].getPath() == false) {
                while(pathType[randomIndex] != "1" || pathType[randomIndex] != "2") {
                    randomIndex = rand() % 6 + 1;
                    if(pathType[randomIndex] == "1" || pathType[randomIndex] == "2") {
                        break;
                    }
                }
                cout<<descripton[randomIndex]<<endl;
                if(chars[player_index].getAdvisor() == advisorArray[randomIndex]) { //TODO:Implement a way to check advisor
                    cout<<"Due to your advisor "<<chars[player_index].getAdvisor()<<", you can safley bypass the event."<<endl;
                } else {
                    cout<<"This event has caused a change in your pride points. Pride Points added: "<<points[randomIndex]<<endl;
                    chars[player_index].addPridePoints(stoi(points[randomIndex]));
                }
            } else if(chars[player_index].getPath() == true) {
                while(pathType[randomIndex] != "0" || pathType[randomIndex] != "2") {
                    randomIndex = rand() % 6 + 1;
                    cout<<randomIndex<<endl;
                    if(pathType[randomIndex] == "0" || pathType[randomIndex] == "2") {
                        break;
                    }
                }
                cout<<descripton[randomIndex]<<endl;
                if(chars[player_index].getAdvisor() == advisorArray[randomIndex]) { //TODO:Implement a way to check advisor
                    cout<<"Due to your advisor "<<chars[player_index].getAdvisor()<<", you can safley bypass the event."<<endl;
                } else {
                    cout<<"This event has caused a change in your pride points. Pride Points added: "<<points[randomIndex]<<endl;
                    chars[player_index].addPridePoints(stoi(points[randomIndex]));
                }
            }
        }
    } else if (tile.color == 'B') {
        cout << "Oasis Tile: Gain 200 points to all attributes and an extra turn!" << endl;
        chars[player_index].oasisTile();
    } else if (tile.color == 'P') {
        cout << "Counseling Tile: Gain 300 points and choose an advisor!" << endl;
        chars[player_index].counselingTile();
        if(chars[player_index].getAdvisor() == "") {
            cout<<"To go to Cub Training, you must select an adviosr to guide you."<<endl;

            string AdivsorName[5] = {"Rafiki - Invisibility ", "Nala - Night Vision", "Sarabi - Energy Manipulation", "Zazu - Weather Control", "Sarafina - Super Speed"};

            for(int i = 0; i < 5; i++){
                cout << i+1 << ") " << AdivsorName[i] << endl;
            }

            cout<<"Input the corresponding number to choose an advisor."<<endl;
            int input = 0;
            cin>>input;
            

            chars[player_index].setAdvisor(AdivsorName[input - 1]);
        }
      
    } else if (tile.color == 'R') {
        cout << "Graveyard Tile: Move back 10 tiles and lose 100 points!" << endl;
        _player_position[player_index] = max(0, pos - 10);
        chars[player_index].graveyardTile();
    } else if (tile.color == 'N') {
        cout << "Hyenas Tile: Return to previous position and lose 300 stamina!" << endl;
        _player_position[player_index] = max(0, pos - 1); // Example logic for previous position
         chars[player_index].heynaTile();
    } else if (tile.color == 'U') {
        cout << "Time for a test of wits! Answer a riddle and you'll earn a boost of 500 Points to your Wisdom Trait, your cleverness pays off!" << endl;
        ifstream inputFile("riddles.txt");  // Open the file with the questions and answers
        if (!inputFile) {
            cout << "Could not open the file!" << endl;
        }
        string line;
        const int MAX_QUESTIONS = 100;  // Maximum number of questions you want to store
        string questions[MAX_QUESTIONS];
        string answers[MAX_QUESTIONS];
        int questionCount = 0;

        while (getline(inputFile, line) && questionCount < MAX_QUESTIONS) {
            string parts[2];  // Array to store the question and answer parts

            int splitCount = split(line, '|', parts, 2);

            if (splitCount == 2) {
                questions[questionCount] = parts[0];  // First part is the question
                answers[questionCount] = parts[1];    // Second part is the answer
                questionCount++;
            } else if (splitCount == -1) {
                cout << "Error: Line exceeded maximum splits." << endl;
            } else if (splitCount == 0) {
                cout << "Error: Empty line encountered." << endl;
            }
        }

        inputFile.close();  

        string ans = " ";

        int randomIndex = rand() % questionCount; 
        cout << "Question: " << questions[randomIndex] << endl;
        cin >> ans;
        if(ans == answers[randomIndex]){
             cout << "Correct enjoy 500 points!" << endl;
             chars[player_index].addWisdom(500);
        }else{
            cout << "no" << endl;
        }
    }
}


int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}