#include "Player.h"

std::ostream& operator<< (std::ostream& s, Player& player) {
		return s << "Nazwisko: " << player.get_name() << '\n'
		<< "Nr: " << player.get_nr() << '\n'
		<< "Kondycja: " << player.get_endurance() << '\n'
		<< "Sila: " << player.get_strength() << '\n';

	//for (Endurance_workout ew : player.get_endurance_workouts()) {
	//	s << ew;
	//}

	//for (Strength_workout sw : player.get_strength_workouts()) {
	//	s << sw;
	//}
	
}