#pragma once

#include "Equippable.h"

class Weapon : public Equippable
{
private:

	int damage;

public:

	Weapon(std::string _name, std::string _description, int _price, int _weight, int _damage);
};