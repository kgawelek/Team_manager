#pragma once
#include <iostream>
class Date
{
private:
	int day, month, year;

public:
	Date(int d, int m, int y);

	int get_day() { return this->day; };
	int get_month() { return this->month; };
	int get_year() { return this->year; };

	void set_date(int d, int m, int y);

	bool prev_month(Date date);
	bool prev_year(Date date);
};

std::ostream& operator<< (std::ostream& s, Date& d);