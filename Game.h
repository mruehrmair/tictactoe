#pragma once
#include <array>
#include "Player.h"

class Game
{

public:
    const static int SIZE = 3;
    const static int GAMERUNNING = 1;
    const static int GAMEEND = 0;
    const static int PLAYERWON = 2;
    const static int FIELDTAKEN = 3;
    const static int GAMEDRAW = 4;
    const static int EMPTYFIELD = 0;
    int getGameState() const &;
    void move(int x, int y);
    int getGameboardField(int x, int y) const;
    void setPlayers(std::array<Player, 2> const &players);
    Player getActivePlayer();
    int getTurnNumber();
    void startGame();
    void stopGame();
    void endTurn();

private:
    int turnNumber = 0;
    int gameState = GAMEEND;
    void initGameBoard();
    void checkWin(int activePlayerNumber);
    void checkDraw();
    std::array<std::array<int, SIZE>, SIZE> gameboard;
    std::array<Player, 2> players;
};