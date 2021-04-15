#include "Team.h"
#include <fstream>
#include <algorithm>

Endurance_coach* Team::find_endurance_coach(std::string name) {
	List_Element<Endurance_coach>* head = endurance_coaches.get_head();


		while (head) {
			if (head->get_element().get_name() == name)
				return &(head->get_element());
			else
				head = head->get_next();
		}
		std::cout << "Nie znaleziono trenera o nazwisku " + name << '\n';
		return nullptr;
}

Strength_coach* Team::find_strength_coach(std::string name) {
	List_Element<Strength_coach>* head = strength_coaches.get_head();

		while (head) {
			if (head->get_element().get_name() == name)
				return &(head->get_element());
			else
				head = head->get_next();
		}
		std::cout << "Nie znaleziono trenera o nazwisku " + name << '\n';
		return nullptr;

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


void Team::player_stats() {
	std::string name;
	int nr;
	std::cout << "Podaj nazwisko zawodnika: ";
	std::cin >> name;
	std::cout << "Podaj nr zawodnika: ";
	std::cin >> nr;

	std::list<Player>::iterator it = std::find_if(players.begin(), players.end(), [name, nr](Player p) {
		if (p.get_name() == name && p.get_nr() == nr)
			return true;
		else
			return false;
		});

	if (it != players.end()) {
		std::cout << "Kondycja: " << (*it).get_endurance() << '\n'
			<< "Sila: " << (*it).get_strength() << '\n';
	}
	else {
		std::cout << "Podano dane zawodnika, ktory nie istnieje" << '\n';
	}
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

