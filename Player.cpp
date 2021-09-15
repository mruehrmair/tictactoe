#include "Player.h"
#include <string>

Player::Player(int number, std::string name) : number(number), name(name)
{
}

std::string Player::getName() const
{
    return name;
}

int Player::getNumber() const
{
    return number;
}