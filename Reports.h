#pragma once
#include "Team.h"

class Reports
{
private:
	Team team;

public:
	Reports(Team& team): team(team) {};

	void report_choice();
	void personal_report_endurance(Player player);
	void personal_report_strength(Player player);
	void all_players_report();

};

