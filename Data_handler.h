#pragma once
#include "Team.h"
#include <fstream>

class Data_handler
{

public:
	void read_players_list(std::string file_name, Team &team);
	void read_stregth_coaches(std::string file_name, Team& team);
	void read_endurance_coaches(std::string file_name, Team& team);

	void save_players_data(std::string players_file_name, Team& team);
	void save_endurance_coaches_data(std::string file_name, Team& team);
	void save_strength_coaches_data(std::string file_name, Team& team);
};

