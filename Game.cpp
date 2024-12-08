//Game.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h"
#include "Board.h"

using namespace std;


// Fix chooseChar (get name and age to print)
// Fix Main Menu
// Fix board (random color probablities)(tranfer) - done
// Move the player after each turn - done
//
Game::Game(Player players[], Board board, int turn) {
    // player[0] = players[0];
    // player[1] = players[1];
    gameBoard = board;
    currentTurn = turn;
}
int Game::split(string input_string, char separator, string arr[], const int ARR_SIZE) {
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



void Game::chooseCharacters(Player player[], int playerIndex){
    displayCharacters();
    cout<<"Player "<< playerIndex+1 <<", choose your character."<<endl;
    cout<<"Input the corresponding number to choose a character."<<endl;
    int input = 0;
    cin>>input;
    ifstream file("character.txt");
    string line;
    string arr[6];
    if(file.fail()) {
        cout<<"Could not open file."<<endl;
        return;
    }
    while(getline(file, line)) {
        split(line, '|', arr, 6);
        if(input == 1 && arr[0] == "Apollo") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        } else if(input == 2 && arr[0] == "Mane") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        } else if(input == 3 && arr[0] == "Elsa") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        } else if(input == 4 && arr[0] == "Zuri") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        } else if(input == 5 && arr[0] == "Roary") {
            player[playerIndex].setName(arr[0]);
            player[playerIndex].setAge(stoi(arr[1]));
            player[playerIndex].setStrength(stoi(arr[2]));
            player[playerIndex].setStamina(stoi(arr[3]));
            player[playerIndex].setWisdom(stoi(arr[4]));
        }
    }
}

void Game::chooseAdvisor(Player player){

    cout<<"To go to Cub Training, you must select an adviosr to guide you."<<endl;

    string AdivsorName[5] = {"Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"};

    for(int i = 0; i < 5; i++){
        cout << i+1 << ") " << AdivsorName[i] << endl;
    }

    cout<<"Input the corresponding number to choose an advisor."<<endl;
    int input = 0;
    cin>>input;
    

    player.setAdvisor(AdivsorName[input - 1]);

}
void Game::displayCharacters() {
    ifstream file("character.txt");
    string line;
    int count = 0;
    if(file.fail()) {
        cout<<"Could not open file."<<endl;
        return;
    }
    cout<<"Characters to choose from: "<<endl;
    while(getline(file, line)) {
        cout<<count<<" - "<<line<<endl;
        count++;
    }
}

void Game::displayMainMenu() {
        int choice;
        do {
            cout << "Main Menu:" << endl;
            cout << "1. Check Player Progress" << endl;
            cout << "2. Review Character" << endl;
            cout << "3. Check Position" << endl;
            cout << "4. Review Advisor" << endl;
            cout << "5. Move Forward" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    player[currentTurn].printStats();
                    break;
                case 2:
                    cout << "Character: " << player[currentTurn].getName() << endl;
                    break;
                case 3:
                    gameBoard.displayBoard();
                    break;
                case 4:
                    if(player[currentTurn].getAdvisor() == "") {
                        cout << "No current Advisor" << endl;
                    } else {
                        cout << "Advisor: " << player[currentTurn].getAdvisor() << endl;
                    }
                    break;
                case 5:
                    // Simulate dice roll (1-6)
                    int steps = (rand() % 6) + 1;
                    cout << "You rolled a " << steps << endl;
                    gameBoard.movePlayer(currentTurn, steps);
                    break;
            }
        } while (choice != 5);
    }


void Game::selectPath() {
    for(int i = 0; i < 2; i++){
        cout << "Player "<<i+1<<", choose your path:"<<endl;
        cout<<"1. Pridelands\n2. Cub Training"<<endl;
        int choice;
        cin >> choice;

        while(choice < 1 || choice > 2){
            cout << "Invalid choice, try again." << endl;
            cout << "Player "<<i+1<<", choose your path:"<<endl;
            cout<<"1. Pridelands\n2. Cub Training"<<endl;
            cin >> choice;
        }
        if(choice == 1){
            player[i].toPrideLands();
        }
        else if(choice == 2){
            player[i].trainCub();
            chooseAdvisor(player[i]);
        }
    }    
}

void Game::playGame() {
        gameBoard = Board(2);  // Initialize board for 2 players
        currentTurn = 0;
        // player[currentTurn].printStats();

        while (true) {
            // Display current board state
            cout << "Current Board State:" << endl;
            gameBoard.displayBoard();
            cout << endl;

            // Display current player's stats
            cout << "Player " << currentTurn + 1 << " Turn:" << endl;
            // player[currentTurn].printStats();

            // Main menu
            displayMainMenu();

            // Switch turns
            currentTurn = (currentTurn + 1) % 2;

            // Check win condition (when a player reaches the end)
            if (gameBoard.getPlayerPosition(0) == 51 && gameBoard.getPlayerPosition(1) == 51) {
                determineWinner();
                break;
            }
        }

        // // Determine winner
        // determineWinner();
    }
void Game::determineWinner(){
    if(player[0].getPridePoints() > player[1].getPridePoints()){
        cout<< "Player 1 Wins! :D" << endl;
        cout<<"Player 1 stats:"<<endl;
        player[0].printStats();
        cout<<"Player 2 stats:"<<endl;
        player[1].printStats();
    }
    else if(player[0].getPridePoints() < player[1].getPridePoints()){
        cout<< "Player 2 Wins! :D" << endl;
        cout<<"Player 1 stats:"<<endl;
        player[0].printStats();
        cout<<"Player 2 stats:"<<endl;
        player[1].printStats();
    }else{
        cout << "It's a Tie!!!" << endl;
        cout<<"Player 1 stats:"<<endl;
        player[0].printStats();
        cout<<"Player 2 stats:"<<endl;
        player[1].printStats();
    }
}

void Game::run() {
    srand(time(0));
    Game game(player, gameBoard, currentTurn);

    for(int i = 0; i < 2; i++) {
        game.chooseCharacters(player, i);
    }

    system("cls"); //clears the terminal so it looks clean (found it on stackoverflow)

    player[0].printStats();
    cout << endl;
    player[1].printStats();
    game.selectPath();
    cout<< endl;

    system("cls");

    game.playGame();
}