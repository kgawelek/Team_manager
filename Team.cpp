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

std::list<Player>::iterator Team::find_player() {
	std::string name;
	int nr;
	std::cout << "Podaj nazwisko zawodnika: ";
	std::cin >> name;
	std::cout << "Podaj nr zawodnika: ";
	std::cin >> nr;

	std::list<Player>::iterator it = std::find_if(this->players.begin(), this->players.end(), [name, nr](Player p) {
		if (p.get_name() == name && p.get_nr() == nr)
			return true;
		else
			return false;
		});

	return it;
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

	std::list<Player>::iterator it = find_player();

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

	std::list<Player>::iterator it = find_player();

	if (it != players.end()) {
		int type;
		std::string coach_name;
		int length;
		int day, month, year;

		std::cout << "Wybierz typ treningu: \n 1. Wytrzymalosciowy \n 2. Silowy \n";
		std::cin >> type;

		std::cout << "Podaj nazwisko trenera \n";
		std::cin >> coach_name;

		std::cout << "Podaj date: \ndzien:";
		std::cin >> day;
		std::cout << "miesiac:";
		std::cin >> month;
		std::cout << "rok:";
		std::cin >> year;

		if (type == 1) { // endurance
			
			std::cout << "Podaj dlugosc treningu w minutach \n";
			std::cin >> length;

			Endurance_coach* ec = this->find_endurance_coach(coach_name);
			if (ec) {
				Endurance_workout ew(length, ec, Date(day, month, year), false, (*it).get_endurance());
				(*it).add_endurance_workout(ew);
			}
		}
		else if (type == 2) { // strength

			std::cout << "Podaj ilosc cwiczen \n";
			std::cin >> length;

			Strength_coach* sc = this->find_strength_coach(coach_name);
			if (sc) {
				Strength_workout sw(length, sc, Date(day, month, year), false, (*it).get_strength());
				(*it).add_strength_workout(sw);
			}
		}
		else {
			std::cout << "Wybrano bledny typ treningu \n";
		}
	}
	else {
		std::cout << "Podano dane zawodnika, ktory nie istnieje" << '\n';
	}


}

void Team::reports() {
	//TODO: implement - 6
}

void Team::add_coach() {

	int type;
	std::string name;
	double bonus;

	std::cout << "Wybierz typ trenera:\n 1. Wytrzymalosci \n 2.Sily\n Wybor:";
	std::cin >> type;
	std::cout << "Podaj nazwisko trenera: ";
	std::cin >> name;
	std::cout << "Podaj bonus trenera: ";
	std::cin >> bonus;

	if (type == 1) {
		this->endurance_coaches.add_element(Endurance_coach(name, bonus));
	}
	else if (type == 2) {
		this->strength_coaches.add_element(Strength_coach(name, bonus));
	}
	else {
		std::cout << "Podano nieprawidlowy typ trenera\n";
	}


}


void Team::print_coach_list() {

	std::cout << "Trenerzy wytrzymalosci: \n\n";
	this->endurance_coaches.print_elements(std::cout);

	std::cout << "Trenerzy silowi: \n\n";
	this->strength_coaches.print_elements(std::cout);

}

void Team::workouts_history() {

	std::list<Player>::iterator it = find_player();

	std::cout << "Treningi wytrzymalosciowe:" << '\n';
	for (Endurance_workout ew : (*it).get_endurance_workouts()) {
		std::cout << ew.get_coach()->get_name() << '\n'
			<< "Minuty treningu: " << ew.get_minutes_of_workout() << '\n'
			<< ew.get_date().get_day() << "." << ew.get_date().get_month() << "." << ew.get_date().get_year() << '\n';

		std::cout << "Trening wykonany: ";
		if (ew.get_is_done())
			std::cout << "Tak" << '\n';
		else
			std::cout << "Nie" << '\n';
	}


	std::cout << "Treningi silowe:" << '\n';
	for (Strength_workout sw : (*it).get_strength_workouts()) {
		std::cout << sw.get_coach()->get_name() << '\n'
			<< "Ilosc cwiczen: " << sw.get_nr_of_excercises() << '\n'
			<< sw.get_date().get_day() << "." << sw.get_date().get_month() << "." << sw.get_date().get_year() << '\n';
			
		std::cout << "Trening wykonany: ";
		if (sw.get_is_done())
			std::cout << "Tak" << '\n';
		else
			std::cout << "Nie" << '\n';
	}
}

void Team::change_workout_status() {
	//TODO: implement - 3
}

