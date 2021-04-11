#pragma once
#include <iostream>
class Coach
{
protected:
	std::string name;

public:
	std::string get_name() { return this->name; };
	Coach() = default;
	Coach(std::string n) : name(n) {};
};

