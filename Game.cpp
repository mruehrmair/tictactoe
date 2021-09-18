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
    int number = getActivePlayer().getNumber();
    if (gameboard[x][y] == 0)
    {
        gameboard[x][y] = number;
        gameState = Game::GAMERUNNING;
    }
    else
    {
        gameState = Game::FIELDTAKEN;
    }
    checkWin(number);
}

void Game::checkWin(int activePlayerNumber)
{
    for (int i = 0; i < SIZE; i++)
    {
        //check row
        for (int j = 0; j < SIZE; j++)
        {
            if (gameboard[i][j] != activePlayerNumber)
                break;
            if (j == SIZE - 1)
            {
                gameState = Game::PLAYERWON;
                return;
            }
        }
        //check col
        for (int j = 0; j < SIZE; j++)
        {
            if (gameboard[j][i] != activePlayerNumber)
                break;
            if (j == SIZE - 1)
            {
                gameState = Game::PLAYERWON;
                return;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        //check diag
        if (gameboard[i][i] != activePlayerNumber)
            break;
        if (i == SIZE - 1)
        {
            gameState = Game::PLAYERWON;
            return;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
       //check anti-diag
        if (gameboard[i][(SIZE - 1) - i] != activePlayerNumber)
            break;
        if (i == SIZE - 1)
        {
            gameState = Game::PLAYERWON;
            return;
        } 
    }
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
    Game::players[0].setActive(true);
    Game::players[1].setActive(false);
    gameState = GAMERUNNING;
}
void Game::stopGame()
{
    turnNumber = 0;
    initGameBoard();
    gameState = GAMEEND;
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
