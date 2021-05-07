#pragma once
#include "Player.h"
#include <vector>
#include "Endurance_coach.h"
#include "Strength_coach.h"
#include <list>
#include "My_list.h"


class Team
{

private:
	std::list<Player> players; 
	My_list<Endurance_coach> endurance_coaches; 
	My_list<Strength_coach> strength_coaches; 


public:
	std::list<Player> get_players() { return this->players; };
	My_list<Endurance_coach> get_endurance_coaches() { return this->endurance_coaches; };
	My_list<Strength_coach> get_strength_coaches() { return this->strength_coaches; };

	

	std::list<Player>::iterator find_player();
	Endurance_coach* find_endurance_coach(std::string name);
	Strength_coach* find_strength_coach(std::string name);


	// user options:
	void print_players();
	void add_player();
	void remove_player();
	void add_workout();
	void add_coach();
	void workouts_history();
	void change_workout_status();
	void player_stats();
	void print_coach_list();


	friend class Data_handler;
};

