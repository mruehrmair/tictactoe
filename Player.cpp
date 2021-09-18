#include "Player.h"
#include <string>

Player::Player(int number, std::string name) : number(number), name(name)
{
}

Player::Player()
{
    number = 0;
}

std::string Player::getName() const
{
    return name;
}

int Player::getNumber() const
{
    return number;
}