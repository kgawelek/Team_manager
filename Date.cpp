#include "Date.h"

std::ostream& operator << (std::ostream& s, Date& d) {
	return s << d.get_day() << "." << d.get_month() << "." << d.get_year() << 'n';
}