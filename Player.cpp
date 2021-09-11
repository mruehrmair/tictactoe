#include "Player.h"
#include <string>

Player::Player(int number, std::string name) : number(number), name(name)
{
}

std::string Player::getName()
{
    return name;
}

int Player::getNumber()
{
    return number;
}