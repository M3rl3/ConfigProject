#include <iostream>
#include <ostream>
#include <string>

#include "Game.h"

void Game::printArray() {

    std::cout << "\n";
    std::cout << "\t00   |01   |02   \n";
    std::cout << "\t  " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << " \n";
    std::cout << "\t_____|_____|_____\n";
    std::cout << "\t10   |11   |12   \n";
    std::cout << "\t  " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << " \n";
    std::cout << "\t_____|_____|_____\n";
    std::cout << "\t20   |21   |22   \n";
    std::cout << "\t  " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << " \n";
    std::cout << "\t     |     |     \n";
}

void Game::handleTurns() {
    if (turn == 'X') {
        std::cout << "\n[X]: ";
    }
    else if (turn == 'O') {
        std::cout << "\n[O]: ";
    }
    
    std::cin >> row >> column;

    //Saves state if move is 33
    if (row == 3 && column == 3) {
        gameState.SaveState(arr);
        printArray();
        return;
    }
    
    //Loads previous state if move is 44
    else if (row == 4 && column == 4) {
        gameState.LoadState(arr);
        printArray();
        return;
    }
    
    //Change game language if move is 55
    else if (row == 5 && column == 5) {
        gameState.GameLocale();
    }
    
    //Exits game if move is 66
    else if (row == 6 && column == 6) {
        exit(0);
    }

    if (turn == 'X' && arr[row][column] != 'X' && arr[row][column] != 'O') {
        //update the position for X if not already occupied
        arr[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && arr[row][column] != 'X' && arr[row][column] != 'O') {
        //update the position for X if not already occupied
        arr[row][column] = 'O';
        turn = 'X';
    }
    else {
        //if input position is already filled
        printArray();
        return;
    }
    printArray();
}

bool Game::gameOver() {
    //condition for simple rows and columns
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] || arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
            std::cout << "\nYou Win!";
            std::cout << "\nVous gagnez!";
            return false;
        }      
    }
    
    //condition for diagonals
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] || arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) {
        std::cout << "\nYou Win!";
        std::cout << "\nVous gagnez!";
        return false;
    }
        
    //condition if game may still continue
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != 'X' && arr[i][j] != 'O') {
                return true;
            }        
        }
    }         

    return false;
}