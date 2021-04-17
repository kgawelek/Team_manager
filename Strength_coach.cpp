#include "Strength_coach.h"

std::ostream& operator<< (std::ostream& s, Strength_coach& sc) {
	return s << "Nazwisko: " << sc.get_name() << '\n'
		<< "Bonus: " << sc.get_bonus() << '\n';

}