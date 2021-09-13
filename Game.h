#pragma once
#include <array>
#include "Player.h"

class Game
{
private:
    std::array<std::array<int, 3>, 3> gameboard;

public:
    const static int PLAYERWON=2;
	const static int FIELDTAKEN=1;
	const static int GAMEDRAW=3;
	const static int GAMEEND=4;
    Game();
    int move(Player const& player);
};