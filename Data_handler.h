#pragma once
#include "Team.h"
#include <fstream>

class Data_handler
{
private:
	std::string players_data;
	std::string endurance_coaches_data;
	std::string strength_coaches_data;

public:

	Data_handler() {};
	Data_handler(std::string players_data,
		std::string endurance_coaches_data,
		std::string strength_coaches_data) :
		players_data(players_data), endurance_coaches_data(endurance_coaches_data), strength_coaches_data(strength_coaches_data) {};

	void read_data(Team& team);

	void read_players_list(std::string file_name, Team &team);
	void read_strength_coaches(std::string file_name, Team& team);
	void read_endurance_coaches(std::string file_name, Team& team);


	void save_data(Team& team);

	void save_players_data(std::string players_file_name, Team& team);
	void save_endurance_coaches_data(std::string file_name, Team& team);
	void save_strength_coaches_data(std::string file_name, Team& team);
};

