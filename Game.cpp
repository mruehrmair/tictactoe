#include <array>
#include "Player.h"
#include "Game.h"

void Game::initGameBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            gameboard[i][j] = EMPTYFIELD;
        }
    }
}

int Game::getGameState() const &
{
    return Game::gameState;
}

void Game::move(int x, int y)
{
    //TODO Exception handling on wrong input
    int number = getActivePlayer().getNumber();
    if (gameboard[x][y] == EMPTYFIELD)
    {
        gameboard[x][y] = number;
        gameState = Game::GAMERUNNING;
    }
    else
    {
        gameState = Game::FIELDTAKEN;
    }
    checkWin(number, x, y);
    if (gameState == Game::GAMERUNNING)
    {
        checkDraw();
    }
}

void Game::aiMove()
{
    int x = randomNumber(2);
    int y = randomNumber(2);
    move(x, y);
    while (gameState == Game::FIELDTAKEN)
    {
        x = randomNumber(2);
        y = randomNumber(2);
        move(x, y);
    }
}

void Game::checkDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (gameboard[i][j] == EMPTYFIELD)
            {
                //still empty fields left
                return;
            }
        }
    }
    //no empty fields left
    gameState = GAMEDRAW;
}

bool Game::checkWin(int activePlayerNumber, int x, int y)
{
    for (int i = 0; i < SIZE; i++)
    {
        //check row
        if (gameboard[x][i] != activePlayerNumber)
            break;
        if (i == SIZE - 1)
        {
            gameState = Game::PLAYERWON;
            return true;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        //check col
        if (gameboard[i][y] != activePlayerNumber)
            break;
        if (i == SIZE - 1)
        {
            gameState = Game::PLAYERWON;
            return true;
        }
    }
    //check diag
    if (x == y)
    {
        for (int i = 0; i < SIZE; i++)
        {

            if (gameboard[i][i] != activePlayerNumber)
                break;
            if (i == SIZE - 1)
            {
                gameState = Game::PLAYERWON;
                return true;
            }
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
            return true;
        }
    }
    return false;
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

int Game::randomNumber(int max)
{
    int random_integer;
    int lowest = 0, highest = max;
    int range = (highest - lowest) + 1;
    for (int index = 0; index < 20; index++)
    {
        random_integer = lowest + int(range * rand() / (RAND_MAX + 1.0));
    }

    return random_integer;
}
