#include "Strength_workout.h"
std::ostream& operator << (std::ostream& s, Strength_workout& sw) {
	return s << sw.get_coach()->get_name() << '\n'
		<< sw.get_nr_of_excercises() << '\n'
		<< sw.get_date().get_day() << " " << sw.get_date().get_month() << " " << sw.get_date().get_year() << '\n'
		<< int(sw.get_is_done()) << '\n'
		<< sw.get_stat() << '\n' << "." << '\n';
}