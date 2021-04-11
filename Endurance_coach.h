#pragma once
#include "Coach.h"
class Endurance_coach :
    public Coach
{
private:
    double endurance_bonus_per_hour;
public:
    std::string get_name() { return this->name; };
    double get_bonus() { return this->endurance_bonus_per_hour; };
    Endurance_coach() = default;
    Endurance_coach(std::string n, double bonus) : Coach(n), endurance_bonus_per_hour(bonus) {};
};

