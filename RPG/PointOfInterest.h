#pragma once

#include<string>

class PointOfInterest
{
protected:
	std::string name;
	std::string description;

public:
	PointOfInterest(std::string _name, std::string _description) : name(_name), description(_description) {};
};