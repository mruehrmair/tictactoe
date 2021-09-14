#pragma once
#include <array>
#include "Player.h"

class Game
{

public:
    const static int SIZE = 3;
    const static int PLAYERWON = 2;
    const static int FIELDTAKEN = 1;
    const static int GAMEDRAW = 3;
    const static int GAMEEND = 4;
    Game();
    int move(Player& player, int x, int y);
    int getGameboardField(int x, int y);

private:
    std::array<std::array<int, SIZE>, SIZE> gameboard;
};