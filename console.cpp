#include <iostream>
#include <string>
#include "Player.h"
#include "Game.h"

void DisplayGameboard(Game const &game)
{
    for (int i = 0; i < game.SIZE; i++)
    {
        for (int j = 0; j < game.SIZE; j++)
        {
            std::cout << game.getGameboardField(i, j);
        }
        std::cout << std::endl;
    }
}

void Move(Player const &player, Game &game)
{
    std::cout << player.getName() << ", your turn: " << std::endl;
    int x;
    int y;
    std::cin >> x;
    std::cin >> y;
    game.move(player, x, y);
}

int main()
{
    std::string name;
    std::cout << "TicTacToe " << std::endl;
    std::cout << "Player 1, please enter your name: ";
    std::cin >> name;
    std::cout << "Hello, " + name << std::endl;
    const Player playerOne(1, name);
    std::cout << "Player 2, please enter your name: ";
    std::cin >> name;
    std::cout << "Hello, " + name << std::endl;
    const Player playerTwo(2, name);
    std::array<Player, 2> players = {playerOne, playerTwo};
    Game game = Game();
    while (!game.hasGameEnded)
    {
        int size = (int)players.size();
        for (int i = 0; i < size; i++)
        {
            Move(players[i], game);
            DisplayGameboard(game);
        }
        game.hasGameEnded = true;
    }
}