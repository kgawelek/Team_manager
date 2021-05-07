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

void Player::change_endurance_workout_status() {
	
	std::cout << "Treningi wytrzymalosciowe:" << '\n';
	int counter = 0;
	for (Endurance_workout ew : this->endurance_workouts) {
		counter++;
		std::cout << counter << '\n';
		std::cout << ew.get_coach()->get_name() << '\n'
			<< "Minuty treningu: " << ew.get_minutes_of_workout() << '\n'
			<< ew.get_date().get_day() << "." << ew.get_date().get_month() << "." << ew.get_date().get_year() << '\n';

		std::cout << "Trening wykonany: ";
		if (ew.get_is_done())
			std::cout << "Tak" << '\n';
		else
			std::cout << "Nie" << '\n';

	}
	int workout_nr = 0;
	std::cout << "Wybierz nr treningu: ";
	std::cin >> workout_nr;

	int status_choice = 0;
	bool is_done;

	std::cout << "Trening zostal wykonany? \n1. Tak \n2. Nie\n Wybor: ";
	std::cin >> status_choice;
	if (status_choice == 1)
		is_done = true;
	else if (status_choice == 2)
		is_done = false;
	else {
		std::cout << "Bledny wybor!\n";
		return;
	}

	if (workout_nr > 0 && workout_nr <= counter) {
		if (is_done) {
			this->endurance_workouts[workout_nr - 1].set_is_done(true);
			this->endurance_workouts[workout_nr - 1].set_is_missed(false);
			//changing stats
			this->endurance += endurance_workouts[workout_nr - 1].get_coach()->get_bonus() * endurance_workouts[workout_nr - 1].get_minutes_of_workout() / 60;
		}
		else {
			this->endurance_workouts[workout_nr - 1].set_is_missed(true);
			this->endurance_workouts[workout_nr - 1].set_is_done(false);
			//changing stats
			this->endurance -= endurance_workouts[workout_nr - 1].get_coach()->get_bonus() * endurance_workouts[workout_nr - 1].get_minutes_of_workout() / 60;
		}
		endurance_workouts[workout_nr - 1].set_stat(this->endurance);

	}
	else {
		std::cout << "Nieprawidlowy nr trenignu!\n";
	}


}


void Player::change_strength_workout_status() {
	
	std::cout << "Treningi silowe:" << '\n';
	int counter = 0;
	for (Strength_workout sw : this->strength_workouts) {
		counter++;
		std::cout << counter << '\n';
		std::cout << sw.get_coach()->get_name() << '\n'
			<< "Liczba cwiczen: " << sw.get_nr_of_excercises() << '\n'
			<< sw.get_date().get_day() << "." << sw.get_date().get_month() << "." << sw.get_date().get_year() << '\n';

		std::cout << "Trening wykonany: ";
		if (sw.get_is_done())
			std::cout << "Tak" << '\n';
		else
			std::cout << "Nie" << '\n';

	}
	int workout_nr = 0;
	std::cout << "Wybierz nr treningu: ";
	std::cin >> workout_nr;

	int status_choice = 0;
	bool is_done;

	std::cout << "Trening zostal wykonany? \n1. Tak \n2. Nie\n Wybor: ";
	std::cin >> status_choice;
	if (status_choice == 1)
		is_done = true;
	else if (status_choice == 2)
		is_done = false;
	else {
		std::cout << "Bledny wybor!\n";
		return;
	}

	if (workout_nr > 0 && workout_nr <= counter) {
		if (is_done) {
			this->strength_workouts[workout_nr - 1].set_is_done(true);
			this->strength_workouts[workout_nr - 1].set_is_missed(false);
			//changing stats
			this->strength += strength_workouts[workout_nr - 1].get_coach()->get_bonus() * strength_workouts[workout_nr - 1].get_nr_of_excercises();
		}
		else {
			this->strength_workouts[workout_nr - 1].set_is_missed(true);
			this->strength_workouts[workout_nr - 1].set_is_done(false);
			//changing stats
			this->strength -= strength_workouts[workout_nr - 1].get_coach()->get_bonus() * strength_workouts[workout_nr - 1].get_nr_of_excercises();
		}
		strength_workouts[workout_nr - 1].set_stat(this->strength);
	}
	else {
		std::cout << "Nieprawidlowy nr trenignu!\n";
	}

}

std::ostream& operator<< (std::ostream& s, Player& player) {
		return s << "Nazwisko: " << player.get_name() << '\n'
		<< "Nr: " << player.get_nr() << '\n'
		<< "Kondycja: " << player.get_endurance() << '\n'
		<< "Sila: " << player.get_strength() << '\n';
	
}

