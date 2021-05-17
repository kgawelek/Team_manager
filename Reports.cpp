#include "Reports.h"

void Reports::set_team(Team& team) {
	this->team = team;
}

void Reports::report_choice() {
	int choice;
	std::cout << "Czy chcesz utworzyc raport dla konkretnego zawodnika czy ogolny?\n";
	std::cout << "1. Konkretny zawodnik\n2. Ogolny\n";
	std::cout << "Opcja: ";
	std::cin >> choice;

	if (choice == 1){
		std::list<Player>::iterator it = team.find_player();
		personal_report_endurance(*it);
		personal_report_strength(*it);
	}
	else if (choice == 2){
		all_players_report();
	}
	else {
		std::cout << "Niepoprawna opcja!\n";
	}

}

void Reports::personal_report_endurance(Player player) {

	if (player.get_endurance_workouts().size() > 0) {

		Endurance_workout latest_endurance_workout = player.get_endurance_workouts().back();
		Date latest_endurance_date = latest_endurance_workout.get_date();

		double prev_month_stat = -1;
		for (Endurance_workout ew : player.get_endurance_workouts()) {
			if (latest_endurance_date.prev_month(ew.get_date())) {
				prev_month_stat = ew.get_stat();
				break;
			}
		}

		double prev_year_stat = -1;
		for (Endurance_workout ew : player.get_endurance_workouts()) {
			if (latest_endurance_date.prev_year(ew.get_date())) {
				prev_year_stat = ew.get_stat();
				break;
			}
		}

		std::cout << "Wytrzymalosc w stosunku do ostatniego: \n";
		std::cout << "Miesiaca: ";
		if (prev_month_stat != -1) {
			if (player.get_endurance() - prev_month_stat > 0)
				std::cout << "+" << player.get_endurance() - prev_month_stat << '\n';
			else
				std::cout << player.get_endurance() - prev_month_stat << '\n';
		}
		else {
			std::cout << "Brak danych\n";
		}

		std::cout << "Roku: ";
		if (prev_year_stat != -1) {
			if (player.get_endurance() - prev_year_stat > 0)
				std::cout << "+" << player.get_endurance() - prev_year_stat << '\n';
			else
				std::cout << player.get_endurance() - prev_year_stat << '\n';
		}
		else {
			std::cout << "Brak danych\n";
		}
	}
	
}


void Reports::personal_report_strength(Player player) {

	if (player.get_strength_workouts().size() > 0) {
		Strength_workout latest_strength_workout = player.get_strength_workouts().back();
		Date latest_strength_date = latest_strength_workout.get_date();

		double prev_month_stat = -1;
		for (Strength_workout ew : player.get_strength_workouts()) {
			if (latest_strength_date.prev_month(ew.get_date())) {
				prev_month_stat = ew.get_stat();
				break;
			}
		}

		double prev_year_stat = -1;
		for (Strength_workout ew : player.get_strength_workouts()) {
			if (latest_strength_date.prev_year(ew.get_date())) {
				prev_year_stat = ew.get_stat();
				break;
			}
		}

		std::cout << "Sila w stosunku do ostatniego: \n";
		std::cout << "Miesiaca: ";
		if (prev_month_stat != -1) {
			if (player.get_strength() - prev_month_stat > 0)
				std::cout << "+" << player.get_strength() - prev_month_stat << '\n';
			else
				std::cout << player.get_strength() - prev_month_stat << '\n';
		}
		else {
			std::cout << "Brak danych\n";
		}

		std::cout << "Roku: ";
		if (prev_year_stat != -1) {
			if (player.get_strength() - prev_year_stat > 0)
				std::cout << "+" << player.get_strength() - prev_year_stat << '\n';
			else
				std::cout << player.get_strength() - prev_year_stat << '\n';
		}
		else {
			std::cout << "Brak danych\n";
		}

	}
	
	

}

void Reports::all_players_report() {
	for (Player player: team.get_players()) {
		std::cout << '\n' << player.get_name() << " nr: " << player.get_nr() << '\n';
		personal_report_endurance(player);
		personal_report_strength(player);
	}
}