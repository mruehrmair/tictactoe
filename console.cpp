#include <iostream>
#include <string>
#include "Player.h"
#include "Game.h"

int main()
{
    std::string name;
    std::cout << "TicTacToe "  << std::endl;
    std::cout << "Player 1, please enter your name: ";
    std::cin >> name;
    std::cout << "Hello, " + name << std::endl;
    Player playerOne(1, name);
    std::cout << "Player 2, please enter your name: ";
    std::cin >> name;
    std::cout << "Hello, " + name << std::endl;
    Player playerTwo(2,name);
    Game game = Game();
    game.move(playerOne,2,2);
    game.move(playerOne,1,1);
    std::cout << game.getGameboardField(2,2);
}