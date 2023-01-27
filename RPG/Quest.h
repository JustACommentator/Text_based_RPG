#pragma once
#include <string>

class Quest
{
private:
	
	std::string name;
	std::string description;

public:

	Quest(std::string _name, std::string _description) : name(_name), description(_description) {};
	const std::string getName() { return name; }
	const std::string getDescription() { return description; }

};