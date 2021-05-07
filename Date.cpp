#include "Date.h"

Date::Date(int d, int m, int y) {
	try {
		if (d > 31 || d <= 0)
			throw "Niepoprawny dzien!";
		else if (m > 12 || m <= 0)
			throw "Niepoprawny miesiac!";
		else {
			this->day = d;
			this->month = m;
			this->year = y;
		}
	}
	catch (const char* err) {
		std::cout << err << std::endl;
	}
};

void Date::set_date(int d, int m, int y) {
	try {
		if (d > 31 || d <= 0)
			throw "Niepoprawny dzien!";
		else if (m > 12 || m <= 0)
			throw "Niepoprawny miesiac!";
		else {
			this->day = d;
			this->month = m;
			this->year = y;
		}
	}
	catch (char* err) {
		std::cout << err << std::endl;
	}
}

bool Date::prev_month(Date date) {
	if (this->year == date.get_year() && this->month == date.get_month() + 1)
		return true;
	else if (this->month == 1 && date.get_month() == 12)
		return true;
	else return false;
}

bool Date::prev_year(Date date) {
	return this->year == date.get_year() + 1;
}

std::ostream& operator << (std::ostream& s, Date& d) {
	return s << d.get_day() << "." << d.get_month() << "." << d.get_year() << 'n';
}