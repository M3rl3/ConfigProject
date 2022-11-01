#include <iostream>

#include "Game.h"

int main(int argc, char** argv) {

    std::cout << "\tTic-Tac-Toe\n";
    Game game;
    game.printArray();
    std::cout << "\n\t33 - Save Game";
    std::cout << "\n\t44 - Load Game";
    std::cout << "\n\t55 - Quit Game" << std::endl;
    std::cout << "\nThe Xs and Os are assigned according to \nthe row and column information passed in." << std::endl;
    std::cout << "\nFormat: row <space> column" << std::endl;

    game.turn = 'X';

    while (game.gameOver()) {
        game.handleTurns();
    }

    return 0;
}