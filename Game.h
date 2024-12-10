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
        void chooseAdvisor(Player chars[2], int index);
        void displayCharacters();
        void selectPath(Player chars[2]);
        void playGame(Player chars[2]);
        void determineWinner(Player[]);  
        void displayMainMenu(Player chars[2]);
        int split(string input_string, char separator, string arr[], const int ARR_SIZE);
        void run();
        void statsToPridePoints(Player chars[]);
        void bubbleSort(int arr[],int);
        
};

#endif
