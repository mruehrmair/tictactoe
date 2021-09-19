#pragma once
#include <string>

class Player
{

private:
    int number;
    std::string name;
    bool active;
    bool isAi;

public:
    Player();
    Player(int number, std::string name, bool isAi);
    int getNumber() const;
    std::string getName() const;
    void setActive(bool state);
    bool getActive();
    bool getIsAi();
};