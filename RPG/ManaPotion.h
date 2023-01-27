#pragma once

#include "Consumable.h"

class ManaPotion : public Consumable
{
private:

	int amount;

public:

	ManaPotion(std::string _name, std::string _description, int _weight, int _price, int _amount);
	const int getAmount() { return amount; }
};