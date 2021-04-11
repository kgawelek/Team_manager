#include <iostream>
#include "cli_handler.h"

void start_cli(Team& team) {

	std::cout << "------------------------------------------------" << '\n';

	std::cout << "Witaj w centrum zarzadzania swoja druzyna" << "\n\n";

	int choice = 0;

	while (choice != 10) {
		choice = 0;

		std::cout << "Wybierz opcje:" << '\n';
		std::cout << "[1] Pokaz liste zawodnikow" << '\n';
		std::cout << "[2] Dodaj zawodnika do druzyny" << '\n';
		std::cout << "[3] Usu� zawodnika z druzyny" << '\n';
		std::cout << "[4] Dodaj trening zawodnikowi" << '\n';
		std::cout << "[5] Dodaj nowego trenera" << '\n';
		std::cout << "[6] Centrum raportow" << '\n';
		std::cout << "[7] Przegladaj historie treningow" << '\n';
		std::cout << "[8] Oznacz trening jako wykonany/opuszczony" << '\n';
		std::cout << "[9] Zobacz statystyki zawodnika" << '\n';
		std::cout << "[10] Zakoncz program" << '\n';
		std::cin >> choice;
		try{
		
			switch (choice) {
			case 1:
				team.print_players();
				break;
			case 2:
				team.add_player();
				break;
			case 3:
				team.remove_player();
				break;
			case 4:
				team.add_workout();
				break;
			case 5:
				team.add_coach();
				break;
			case 6:
				team.reports();
				break;
			case 7:
				team.workouts_history();
				break;
			case 8:
				team.change_workout_status();
				break;
			case 9:
				team.player_stats();
				break;
			case 10:
				break;
			default:
				throw "Wybrano niepoprawna opjce";
				break;
			}
		
		}
		catch (const char* err) {
			std::cout << err << '\n';
		}
		


	}
}