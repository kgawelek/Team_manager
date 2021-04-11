#include <iostream>
#include "Team.h"
#include "cli_handler.h"
#include "Data_handler.h"

int main()
{
    Team team;
    Data_handler data;

    std::string players_filename = "players.txt";
    std::string endurance_coaches_filename = "endurance.txt";
    std::string strength_coaches_filename = "strength.txt";

    data.read_endurance_coaches(endurance_coaches_filename, team);
    data.read_stregth_coaches(strength_coaches_filename, team);
    data.read_players_list(players_filename, team);

    start_cli(team);

    data.save_players_data(players_filename, team);
    data.save_strength_coaches_data(strength_coaches_filename, team);
    data.save_endurance_coaches_data(endurance_coaches_filename, team);

    return 0;
}


