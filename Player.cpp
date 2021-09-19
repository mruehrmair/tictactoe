#include "Player.h"
#include <string>

Player::Player(int number, std::string name, bool isAi) : number(number), name(name), isAi(isAi)
{
    active = false;
}

Player::Player()
{
    number = 0;
    active = false;
}

std::string Player::getName() const
{
    return name;
}

int Player::getNumber() const
{
    return number;
}

bool Player::getActive()
{
    return active;
}

void Player::setActive(bool state)
{
    active = state;
}

bool Player::getIsAi()
{
    return isAi;
}