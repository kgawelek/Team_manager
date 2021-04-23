#include <iostream>
#include "Team.h"
#include "Cli_handler.h"
#include "Data_handler.h"

int main()
{
    std::string players_filename = "players.txt";
    std::string endurance_coaches_filename = "endurance.txt";
    std::string strength_coaches_filename = "strength.txt";

    Team team;
    Data_handler data(players_filename, endurance_coaches_filename, strength_coaches_filename);
    Cli_handler cli;

    data.read_data(team);

    cli.start_cli(team);

    data.save_data(team);

    return 0;
}