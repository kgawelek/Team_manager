#include "Team.h"
#include <fstream>
#include <algorithm>

Endurance_coach* Team::find_endurance_coach(std::string name) {
	List_Element<Endurance_coach>* head = endurance_coaches.get_head();

	try {
		while (head) {
			if (head->get_element().get_name() == name)
				return &(head->get_element());
			else
				head = head->get_next();
		}
		throw "Nie znaleziono trenera o nazwisku " + name;
	}
	catch (char * err){
		std::cout << err << '\n';
		return nullptr;

	}
}

Strength_coach* Team::find_strength_coach(std::string name) {
	List_Element<Strength_coach>* head = strength_coaches.get_head();

	try {
		while (head) {
			if (head->get_element().get_name() == name)
				return &(head->get_element());
			else
				head = head->get_next();
		}
		throw "Nie znaleziono trenera o nazwisku " + name;
	}
	catch (char* err) {
		std::cout << err << '\n';
		return nullptr;
	}
}



void Team::print_players() {
	for_each(players.begin(), players.end(), [](Player p) {
		std::cout << p << '\n';
		});
}

void Team::add_player() {
	std::string _name;
	int nr;
	double strength, endurance;
	std::cout << "Podaj jak nazywa sie zawodnik:" << '\n';
	std::cin >> _name;
	std::cout << "Podaj numer zawodnika:" << '\n';
	std::cin >> nr;
	std::cout << "Podaj sile zawodnika:" << '\n';
	std::cin >> strength;
	std::cout << "Podaj wytrzymalosc:" << '\n';
	std::cin >> endurance;

	this->players.push_back(Player(_name, nr, strength, endurance));
}

void Team::remove_player() {
	//TODO: implement - 5
}

void Team::add_workout() {
	//TODO: implement - 2
}

void Team::reports() {
	//TODO: implement - 6
}

void Team::add_coach() {
	//TODO: implement - 4
}

void Team::workouts_history() {
	//TODO: implement - 1
}

void Team::change_workout_status() {
	//TODO: implement - 3
}

void Team::player_stats() {
	//TODO: implement - 1
}