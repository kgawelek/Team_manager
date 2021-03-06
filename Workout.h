#pragma once
#include "Date.h"
class Workout
{
protected:
	Date date;
	bool is_done = false;
	bool is_missed = false;
	double actual_stat;

public:
	Date get_date() { return date; };
	bool get_is_done() { return is_done; };
	bool get_is_missed() { return is_missed; };
	double get_stat() { return actual_stat; };
	void set_date(Date d) { this->date = d; };
	void set_is_done(bool b) { this->is_done = b; };
	void set_is_missed(bool b) { this->is_missed = b; };
	void set_stat(double s) { this->actual_stat = s; };

	Workout() = default;
	Workout(Date d, bool b, double stat) :
		date(d), is_done(b), actual_stat(stat) {};

};

