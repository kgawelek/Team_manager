
#include "Workout.h"
#include "Strength_coach.h"
class Strength_workout :
    public Workout
{
private:
    int nr_of_excercises;
    Strength_coach* coach;

public:
    int get_nr_of_excercises() { return this->nr_of_excercises; };
    Strength_coach* get_coach() { return this->coach; };
    void set_nr_of_excercises(int n) { this->nr_of_excercises = n; };
    void set_coach(Strength_coach* c) { this->coach = c; };

    Strength_workout() = default;
    Strength_workout(int nr, Strength_coach * sc, Date d, bool done, double stat) :
        Workout(d, done, stat), nr_of_excercises(nr), coach(sc) {};
};

std::ostream& operator << (std::ostream& s, Strength_workout& ew);
