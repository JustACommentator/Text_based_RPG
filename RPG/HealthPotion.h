#pragma once

#include "Consumable.h"

class HealthPotion : public Consumable
{
private:

	int amount;

public:

	HealthPotion(std::string _name, std::string _description, int _weight, int _price, int _amount);
	const int getAmount() { return amount; }
};