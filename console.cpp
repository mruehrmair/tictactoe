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

void PlayerInput(Game &game)
{
    std::cout << game.getActivePlayer().getName() << ", your turn: " << std::endl;
    int x;
    int y;
    std::cin >> x;
    std::cin >> y;
    game.move(x, y);
    if (game.getGameState() == game.FIELDTAKEN)
    {
        std::cout << "Unable to use that field, it's already taken!" << std::endl;
        PlayerInput(game);
    }
}

void PlayerTurn(Game &game)
{
    std::cout << "Turn number: " << game.getTurnNumber() << std::endl;
    PlayerInput(game);
}

std::array<Player, 2> InitPlayers()
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
    return players;
}

int main()
{
    Game game = Game();
    game.setPlayers(InitPlayers());
    game.startGame();
    //game loop
    while (!(game.getGameState() == game.GAMEEND))
    {
        PlayerTurn(game);
        DisplayGameboard(game);
        switch (game.getGameState())
        {
        case game.PLAYERWON:
            std::cout << "Congratulations, " << game.getActivePlayer().getName() << ". You win!" << std::endl;
            game.stopGame();
            break;
        }
        game.endTurn();
    }
}