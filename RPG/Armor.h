#pragma once

#include "Equippable.h"

class Armor : public Equippable
{
private:

	int defense;

public:

	Armor(std::string _name, std::string _description, int _price, int _weight, int _defense);

};