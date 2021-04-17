#include "Endurance_coach.h"

std::ostream& operator<< (std::ostream& s, Endurance_coach& ec) {
	return s << "Nazwisko: " << ec.get_name() << '\n'
		<< "Bonus: " << ec.get_bonus() << '\n';

}