#pragma once
#include <iostream>
#include "Endurance_workout.h"
#include "Strength_workout.h"
#include <deque>
#include <algorithm>

class Player
{

private:
	std::string name;
	int number;
	double strength;
	double endurance;
	std::deque<Endurance_workout> endurance_workouts;
	std::deque<Strength_workout> strength_workouts;

public:
	std::string get_name() { return this->name; };
	int get_nr() { return this->number; };
	double get_strength() { return this->strength; };
	double get_endurance() { return this->endurance; };
	std::deque<Endurance_workout> get_endurance_workouts() { return this->endurance_workouts; };
	std::deque<Strength_workout> get_strength_workouts() {	return this->strength_workouts; };


	void set_endurance_workouts(std::deque<Endurance_workout> ew);
	void set_strength_workouts(std::deque<Strength_workout> sw);

	void add_endurance_workout(Endurance_workout ew);
	void add_strength_workout(Strength_workout sw);

	void change_endurance_workout_status();
	void change_strength_workout_status();

	Player() = default;
	Player(std::string name, int number, double strength, double endurance) :
		name(name), number(number), strength(strength), endurance(endurance) {};
	Player(std::string name, int number, double strength, double endurance,
		std::deque<Endurance_workout> endurance_workouts, std::deque<Strength_workout> strength_workouts) :
		name(name), number(number), strength(strength), endurance(endurance),
		endurance_workouts(endurance_workouts), strength_workouts(strength_workouts) {};

};

std::ostream& operator << (std::ostream& s, Player& player);

