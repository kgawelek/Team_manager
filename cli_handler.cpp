#include <iostream>
#include "Cli_handler.h"

void Cli_handler::start_cli(Team& team) {

	std::cout << "------------------------------------------------" << '\n';

	std::cout << "Witaj w centrum zarzadzania swoja druzyna" << "\n\n";

	int choice = 0;

	while (choice != 11) {
		choice = 0;

		std::cout << "Wybierz opcje:" << '\n';
		std::cout << "[1] Pokaz liste zawodnikow" << '\n';
		std::cout << "[2] Dodaj zawodnika do druzyny" << '\n';
		std::cout << "[3] Usun zawodnika z druzyny" << '\n';
		std::cout << "[4] Dodaj trening zawodnikowi" << '\n';
		std::cout << "[5] Dodaj nowego trenera" << '\n';
		std::cout << "[6] Centrum raportow" << '\n';
		std::cout << "[7] Przegladaj historie treningow" << '\n';
		std::cout << "[8] Oznacz trening jako wykonany/opuszczony" << '\n';
		std::cout << "[9] Zobacz statystyki zawodnika" << '\n';
		std::cout << "[10] Lista trenerow" << '\n';
		std::cout << "[11] Zakoncz program" << '\n';
		std::cout << "Opcja: ";
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
				team.print_coach_list();
				break;
			case 11:
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