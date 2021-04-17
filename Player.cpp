#include "Player.h"

void Player::set_endurance_workouts(std::deque<Endurance_workout> ew) {
	this->endurance_workouts = ew;
}

void Player::set_strength_workouts(std::deque<Strength_workout> sw) {
	this->strength_workouts = sw;
}

void Player::add_endurance_workout(Endurance_workout ew) {
	this->endurance_workouts.push_back(ew);
}

void Player::add_strength_workout(Strength_workout sw) {
	this->strength_workouts.push_back(sw);
}

std::ostream& operator<< (std::ostream& s, Player& player) {
		return s << "Nazwisko: " << player.get_name() << '\n'
		<< "Nr: " << player.get_nr() << '\n'
		<< "Kondycja: " << player.get_endurance() << '\n'
		<< "Sila: " << player.get_strength() << '\n';
	
}

