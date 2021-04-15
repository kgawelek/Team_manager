#include "Data_handler.h"

void Data_handler::read_endurance_coaches(std::string file_name, Team& team) {

	std::ifstream file;

	try {
		file.open(file_name);
		std::string temp;
		while (file >> temp && temp != ".") {
			double bonus;
			file >> bonus;
			team.endurance_coaches.add_element(Endurance_coach(temp, bonus));
		}
	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Wystapil blad przy wczytywaniu danych o trenerach przygotowania motorycznego!" << '\n';
	}
}

void Data_handler::read_stregth_coaches(std::string file_name, Team& team) {
	std::ifstream file;

	try {
		file.open(file_name);
		std::string temp;
		while (file >> temp && temp != ".") {
			double bonus;
			file >> bonus;
			team.strength_coaches.add_element(Strength_coach(temp, bonus));

		}
	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Wystapil blad przy wczytywaniu danych o trenerach przygotowania si³owego!" << '\n';
	}
}

void Data_handler::read_players_list(std::string file_name, Team& team) {
	std::ifstream file;
	try {
		file.open(file_name);

		std::string temp;
		while (file >> temp && temp != "-") {
			std::string name = temp;
			int nr;
			double strength, endurance;
			file >> nr >> strength >> endurance;

			std::deque<Endurance_workout> endurance_workouts;
			std::deque<Strength_workout> strength_workouts;

			// endurnace workouts:
			while (file >> temp && temp != ".") {
				int minutes;
				file >> minutes;
				int d, m, y, stat;
				file >> d >> m >> y;
				bool b;
				file >> b;
				file >> stat;

				Endurance_coach* ec = team.find_endurance_coach(temp);
				if(ec){
					Endurance_workout ew(minutes, ec, Date(d, m, y), b, stat);
					endurance_workouts.push_back(ew);
				}
				
				//std::cout << endurance_workouts.back();
			}

			// strength workouts:
			while (file >> temp && temp != ".") {
				int nr_of_exercices;
				file >> nr_of_exercices;
				int d, m, y, stat;
				file >> d >> m >> y;
				bool b;
				file >> b;
				file >> stat;

				Strength_coach* sc = team.find_strength_coach(temp);
				if(sc){
					strength_workouts.push_back(Strength_workout(nr_of_exercices, sc, Date(d, m, y), b, stat));
				}
				
				//std::cout << strength_workouts.back();
			}

			//std::cout << endurance_workouts.size() << '\n';
			//std::cout << strength_workouts.size() << '\n';

			team.players.push_back(Player(name, nr, strength, endurance, endurance_workouts, strength_workouts));

		}
	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Wystapil blad przy wczytywaniu danych!" << '\n';
	}
}

void Data_handler::save_players_data(std::string players_file_name, Team& team) {
	std::ofstream file;

	try {
		file.open(players_file_name);
		for_each(team.players.begin(), team.players.end(), [&file](Player p) {

			file << p.get_name() << '\n'
				<< p.get_nr() << '\n'
				<< p.get_strength() << '\n'
				<< p.get_endurance() << '\n';

			for (Endurance_workout w : p.get_endurance_workouts()) {
				file << w.get_coach()->get_name() << '\n'
					<< w.get_minutes_of_workout() << '\n'
					<< w.get_date().get_day() << ' ' << w.get_date().get_month() << " " << w.get_date().get_year() << '\n'
					<< int(w.get_is_done()) << '\n'
					<< w.get_stat() << "\n";
			}
			file << ".\n";
			for (Strength_workout w : p.get_strength_workouts()) {
				file << w.get_coach()->get_name() << '\n'
					<< w.get_nr_of_excercises() << '\n'
					<< w.get_date().get_day() << ' ' << w.get_date().get_month() << " " << w.get_date().get_year() << '\n'
					<< int(w.get_is_done()) << '\n'
					<< w.get_stat() << "\n";
			}
			file << ".\n";

			});
		file << "-";
	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Wystapil blad przy zapisywaniu danych zawodnikow!" << '\n';
	}

}

void Data_handler::save_endurance_coaches_data(std::string file_name, Team& team) {

	try {
		std::ofstream file;
		file.open(file_name);

		List_Element<Endurance_coach>* head = team.endurance_coaches.get_head();
		while (head) {

			file << head->get_element().get_name() << '\n'
				<< head->get_element().get_bonus() << '\n';

			head = head->get_next();
		}
		file << ".";
	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Wystapil blad przy zapisywaniu danych trenerow przygotowania motorycznego!" << '\n';
	}

}

void Data_handler::save_strength_coaches_data(std::string file_name, Team& team) {

	try {
		std::ofstream file;
		file.open(file_name);

		List_Element<Strength_coach>* head = team.strength_coaches.get_head();
		while (head) {

			file << head->get_element().get_name() << '\n'
				<< head->get_element().get_bonus() << '\n';

			head = head->get_next();
		}
		file << ".";

	}
	catch (const std::ifstream::failure& e) {
		std::cout << "Wystapil blad przy zapisywaniu danych trenerow przygotowania si³owego!" << '\n';
	}
}




