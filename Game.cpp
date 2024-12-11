//Game.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h"
#include "Board.h"

using namespace std;

void Game::bubbleSort(int arr[], int size) {
    bool swapped;

    for(int i = 0; i < size - 1; i++) { //! nested loop (6)
        swapped = false;

        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+ 1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if(!swapped) {
            break;
        }
    }
}

Game::Game(Player players[], Board board, int turn) {
    player[0] = players[0];
    player[1] = players[1];
    gameBoard = board;
    currentTurn = turn;
}
int Game::split(string input_string, char separator, string arr[], const int ARR_SIZE) {
    int count = 0;
    string temp = "";

    if (input_string.length() == 0) { //! If statement(1)
            return 0; 
        }

     for (unsigned int i = 0; i < input_string.length(); i++) { //! Loop (1)
        if (input_string[i] == separator) { //! If statement(2)
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
    
    // while(input < 1 && input > 5) {
    //     cout<<"Invalid choice, try again."<<endl;
    //     cout<<"Player "<< playerIndex+1 <<", choose your character."<<endl;
    //     cout<<"Input the corresponding number to choose a character."<<endl;
    //     cin>>input;
    // }
    ifstream file("character.txt");
    string line;
    string arr[6];
    if(file.fail()) {
        cout<<"Could not open file."<<endl;
        return;
    }
    while(getline(file, line)) { //! loop(2)
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

void Game::chooseAdvisor(Player chars[], int index){

    cout<<"To go to Cub Training, you must select an adviosr to guide you."<<endl;

    string AdivsorName[5] = {"Rafiki - Invisibility ", "Nala - Night Vision", "Sarabi - Energy Manipulation", "Zazu - Weather Control", "Sarafina - Super Speed"};

    for(int i = 0; i < 5; i++){ //! loop(3)
        cout << i+1 << ") " << AdivsorName[i] << endl;
    }

    cout<<"Input the corresponding number to choose an advisor."<<endl;
    int input = 0;
    cin>>input;
    

    chars[index].setAdvisor(AdivsorName[input - 1]);

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

void Game::displayMainMenu(Player chars[]) {
        int choice;
        do {  //! loop(4)
            cout << "Main Menu:" << endl;
            cout << "1. Check Player Progress" << endl;
            cout << "2. Review Character" << endl;
            cout << "3. Check Position" << endl;
            cout << "4. Review Advisor" << endl;
            cout << "5. Leaderboard (Check who's in the lead)" << endl;
            cout << "6. Move Forward" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) { 
                case 1:{
                    string reponse;
                    chars[currentTurn].printStats();
                    cout << "Would you like to convert all leadership traits to pride points? (Y/N)" << endl;
                    cin >> reponse;

                    if(reponse == "Y" || reponse == "y"){
                        cout<<chars[currentTurn].getPridePoints()<<endl;
                        int total2 = 0;
                        total2 += chars[currentTurn].getPridePoints() + ((chars[currentTurn].getStamina() / 100) * 1000) + ((chars[currentTurn].getStrength() / 100) * 1000) + ((chars[currentTurn].getWisdom() / 100) * 1000);

                        chars[currentTurn].setPridePoints(total2);

                        chars[currentTurn].setStrength(100);
                        chars[currentTurn].setStamina(100);
                        chars[currentTurn].setWisdom(100);
                        cout<<chars[currentTurn].getPridePoints()<<endl;
                        
                    }
                    else{
                        cout << "ok bud" << endl;
                    }

                    break;
                }
                case 2:
                    cout << "Character: " << chars[currentTurn].getName() << endl;
                    break;
                case 3:
                    gameBoard.displayBoard(chars[0].getPath(), chars[1].getPath());
                    break;
                case 4:
                    if(chars[currentTurn].getAdvisor() == "") {
                        cout << "No current Advisor" << endl;
                    } else {
                        cout << "Advisor: " << chars[currentTurn].getAdvisor() << endl;
                    }
                    cout << "Would you like to see each advisors power? (Y/N)" <<endl;
                    char res;
                    cin >> res;
                    res = toupper(res);
                    if(res  == 'Y') {
                        cout << endl;
                        string AdvisorPower[5] = {"Rafiki - Invisibility (the ability to become un-seen)", "Nala - Night Vision (the ability to see clearly in darkness)", "Sarabi - Energy Manipulation (the ability to shape and control the properties of energy)", "Zazu - Weather Control (the ability to influence and manipulate weather patterns)", "Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)"};
                        for(int i = 0; i < 5; i++) {
                            cout<<AdvisorPower[i]<<endl;
                        }
                    }
                    break;
                case 5: {
                    int playerPoints[2] = {chars[0].getPridePoints(), chars[1].getPridePoints()};
                    bubbleSort(playerPoints, 2);
                    if(playerPoints[0] == playerPoints[1]) {
                        cout<<"It is currently a tie with both players having "<<playerPoints[0]<<" points."<<endl;
                        break;
                    }
                    if(chars[0].getPridePoints() == playerPoints[0]) {
                        cout<<"Player 1 is in the lead with "<<playerPoints[0]<<" points."<<endl;
                        cout<<"Player 2 is in second place with "<<playerPoints[1]<<" points."<<endl;
                    } else {
                        cout<<"Player 2 is in the lead with "<<playerPoints[0]<<" points."<<endl;
                        cout<<"Player 1 is in second place with "<<playerPoints[1]<<" points."<<endl;
                    }
                    break;
                }
                case 6:{
                    // Simulate dice roll (1-6)
                    int steps = (rand() % 6) + 1;
                    cout << "You rolled a " << steps << endl;
                    gameBoard.movePlayer(currentTurn, steps, chars);
                    break;
                }
                default: {
                    cout<<"Invalid Choice, Try Again."<<endl;
                }
            }
        } while (choice != 6);
    }


void Game::selectPath(Player chars[]) {
    // chars[0] = player[0];
    // chars[1] = player[1];
    for(int i = 0; i < 2; i++){ // !nested for loop (5)
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
            chars[i].toPrideLands();
            chars[i].setPath(false);
        }
        else if(choice == 2){
            chars[i].trainCub();
            chars[i].setPath(true);
            chooseAdvisor(chars, i);
        }
    } 
}

void Game::playGame(Player chars[]) {
        gameBoard = Board(2);  // Initialize board for 2 players
        currentTurn = 0;
        // player[currentTurn].printStats();

        while (true) {
            // Display current board state
            cout << "Current Board State:" << endl;
            gameBoard.displayBoard(chars[0].getPath(), chars[1].getPath());
            cout << endl;

            // Display current player's stats
            cout << "Player " << currentTurn + 1 << " Turn:" << endl;
            // player[currentTurn].printStats();

            // Main menu
            displayMainMenu(chars);

            // Switch turns
            currentTurn = (currentTurn + 1) % 2;

            // Check win condition (when a player reaches the end)
            if (gameBoard.getPlayerPosition(0) == 51 && gameBoard.getPlayerPosition(1) == 51) {  // !if statement(3)
                gameBoard.displayBoard(chars[0].getPath(), chars[1].getPath());
                writeStatsToFile(chars);
                statsToPridePoints(chars);
                determineWinner(chars);
                break;
            }
        }

    }

void Game::writeStatsToFile(Player chars[]){
   ofstream writeF("player_stats.txt"); //! our example of (ofstream) writing to file

    if (!writeF) {
        cout << "Error: Could not open file for writing." << endl;
        return;
    }

    for (int i = 0; i < 2; ++i) {
        writeF << "Player " << i + 1 << " Stats:" << endl;
        writeF << "--------------------" << std::endl;
        writeF << "Charecter Name: " << chars[i].getName() << endl;
        writeF << "Pride Points: " << chars[i].getPridePoints() << endl;
        writeF << "Stamina: " << chars[i].getStamina() << endl;
        writeF << "Strength: " << chars[i].getStrength() << endl;
        writeF << "Wisdom: " << chars[i].getWisdom() << endl;
        writeF << "Path: " << chars[i].getPath() << std::endl;
        writeF << endl;
    }

    writeF.close();
    cout << "Player stats successfully written to 'player_stats.txt'." << endl;
    cout << endl;
}



void Game::determineWinner(Player chars[]){
    if(chars[0].getPridePoints() > chars[1].getPridePoints()){ // !if else statements(4)
        cout<< "Player 1 Wins! :D" << endl;
        cout << endl;
        cout<<"Player 1 stats:"<<endl;
        chars[0].printStats();
        cout << endl;
        cout<<"Player 2 stats:"<<endl;
        chars[1].printStats();
        cout << endl;
    }
    else if(chars[0].getPridePoints() < chars[1].getPridePoints()){
        cout<< "Player 2 Wins! :D" << endl;
        cout << endl;
        cout<<"Player 1 stats:"<<endl;
        chars[0].printStats();
        cout << endl;
        cout<<"Player 2 stats:"<<endl;
        chars[1].printStats();
        cout << endl;
    }else{
        cout << "It's a Tie!!!" << endl;
        cout << endl;
        cout<<"Player 1 stats:"<<endl;
        chars[0].printStats();
        cout << endl;
        cout<<"Player 2 stats:"<<endl;
        chars[1].printStats();
        cout << endl;
    }
}


void Game::statsToPridePoints(Player chars[]) {
    int total1 = 0;
    int total2 = 0;

    total1 += chars[0].getPridePoints() + ((chars[0].getStamina() / 100) * 1000) + ((chars[0].getStrength() / 100) * 1000) + ((chars[0].getWisdom() / 100) * 1000);

    total2 += chars[1].getPridePoints() + ((chars[1].getStamina() / 100) * 1000) + ((chars[1].getStrength() / 100) * 1000) + ((chars[1].getWisdom() / 100) * 1000);

    chars[0].setPridePoints(total1);
    chars[1].setPridePoints(total2);
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
    game.selectPath(player);
    cout<< endl;

    system("cls");

    game.playGame(player);
}