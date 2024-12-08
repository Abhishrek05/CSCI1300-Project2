#include <iostream>
#include "Board.h"
#include "Player.h"
//Game.h

#ifndef GAME_H
#define GAME_H

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
        void playGame();
        void determineWinner();  
        void displayMainMenu();
        int split(string input_string, char separator, string arr[], const int ARR_SIZE);
        void run();
};

#endif
