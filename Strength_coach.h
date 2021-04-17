#pragma once
#include "Coach.h"
class Strength_coach :
    public Coach
{
private:
    double strength_bonus_per_excercise;
public:
    double get_bonus() { return this->strength_bonus_per_excercise; };
    Strength_coach() = default;
    Strength_coach(std::string n, double bonus) : Coach(n), strength_bonus_per_excercise(bonus) {};
};

std::ostream& operator << (std::ostream& s, Strength_coach& sc);
