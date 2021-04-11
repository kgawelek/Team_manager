#include "Endurance_workout.h"

std::ostream& operator << (std::ostream& s, Endurance_workout& ew) {
	return s << ew.get_coach()->get_name() << '\n'
		<< ew.get_minutes_of_workout() << '\n'
		<< ew.get_date().get_day() << " " << ew.get_date().get_month() << " " << ew.get_date().get_year() << '\n'
		<< int(ew.get_is_done()) << '\n'
		<< ew.get_stat() << '\n' << "." << '\n';
}
