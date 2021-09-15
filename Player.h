#pragma once
#include <string>

class Player
{

private:
    int number;
    std::string name;

public:
    Player(int number, std::string name);
    int getNumber() const;
    std::string getName() const;
};