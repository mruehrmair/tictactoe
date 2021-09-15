#include <array>
#include "Player.h"
#include "Game.h"

Game::Game()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            gameboard[i][j] = 0;
        }
    }
}

int Game::move(Player const &player, int x, int y)
{
    if (gameboard[x][y] == 0)
    {
        gameboard[x][y] = player.getNumber();
    }
    else
    {
        return Game::FIELDTAKEN;
    }
    return 0;
}

int Game::getGameboardField(int x, int y) const
{
    return gameboard[x][y];
}