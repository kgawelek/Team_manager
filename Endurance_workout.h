#pragma once
#include "Workout.h"
#include "Endurance_coach.h"
class Endurance_workout :
    public Workout
{
private:
    int minutes_of_workout;
    Endurance_coach* coach;

public:
    int get_minutes_of_workout() { return this->minutes_of_workout; };
    Endurance_coach* get_coach() { return this->coach; };
    void set_minutes_of_workout(int n) { this->minutes_of_workout = n; };
    void set_coach(Endurance_coach* c) { this->coach = c; };

    Endurance_workout() = default;
    Endurance_workout(int min, Endurance_coach* ec,  Date d, bool done, double stat) :
       Workout(d, done, stat), minutes_of_workout(min), coach(ec) {};
};

std::ostream& operator << (std::ostream& s, Endurance_workout& ew);