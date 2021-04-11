#pragma once
#include <iostream>
class Date
{
private:
	int day, month, year;

public:
	int get_day() { return this->day; };
	int get_month() { return this->month; };
	int get_year() { return this->year; };

	void set_date(int d, int m, int y) {
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

	Date(int d, int m, int y) {
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
};

std::ostream& operator<< (std::ostream& s, Date& d);