#pragma once

#include "Item.h"

class Equippable : public Item
{
private:

	bool equipped = true;

public:

	Equippable(std::string _name, std::string _description, int _price, int _weight, Category _category);
	void equip() { equipped = true; }
	void unequip() { equipped = false; }
	const bool getEquipped() { return equipped; }
};