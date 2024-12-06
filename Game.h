#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Board.h"
#include "Board.cpp"
#include "Player.cpp"




class Game{
    private:
        Player player[2];
        Board gameBoard;
        int currentTurn;
    public:
        Game(Player players[2], Board board, int turn);
        void chooseCharacters(Player player[], int playerIndex);
        void chooseAdvisor(Player player);
        void displayCharacters();
        void selectPath();
        void playgame();
        void determineWinner();  
        int split(string input_string, char separator, string arr[], const int ARR_SIZE);
};