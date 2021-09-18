#include <array>
#include "Player.h"
#include "Game.h"

void Game::initGameBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            gameboard[i][j] = 0;
        }
    }
}

int Game::getGameState() const &
{
    return Game::gameState;
}

void Game::move(int x, int y)
{
    if (gameboard[x][y] == 0)
    {
        gameboard[x][y] = getActivePlayer().getNumber();
    }
    else
    {
        gameState = Game::FIELDTAKEN;
    }
    gameState = Game::GAMERUNNING;
}

int Game::getGameboardField(int x, int y) const
{
    return gameboard[x][y];
}

void Game::setPlayers(std::array<Player, 2> const &players)
{
    Game::players = players;
}

Player Game::getActivePlayer()
{
    int size = (int)players.size();
    for (int i = 0; i < size; i++)
    {
        if (players[i].getActive())
        {
            return players[i];
        }
    }
    //something's wrong
    //TODO throw exception
    return Player();
}

void Game::startGame()
{
    turnNumber = 1;
    initGameBoard();
    Game::players[0].setActive(true);
    Game::players[1].setActive(false);
    gameState = GAMERUNNING;
}

int Game::getTurnNumber()
{
    return Game::turnNumber;
}

void Game::endTurn()
{
    turnNumber++;
    int size = (int)players.size();
    for (int i = 0; i < size; i++)
    {
        players[i].setActive(!players[i].getActive());
    }
}
