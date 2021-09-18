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
    bool hasGameEnded = false;
    Game();
    int move(Player const& player, int x, int y);
    int getGameboardField(int x, int y) const;
    void setPlayers(std::array<Player, 2> players);

private:
    std::array<std::array<int, SIZE>, SIZE> gameboard;
    std::array<Player, 2> players;
    
};