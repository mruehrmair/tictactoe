#pragma once
#include <string>

class Player
{

private:
    int number;
    std::string name;
    bool active;

public:
    Player();
    Player(int number, std::string name);
    int getNumber() const;
    std::string getName() const;
    void setActive(bool state);
    bool getActive();
};