#pragma once

#include "Item.h"

class Consumable : public Item
{

private:

	Category potionType;

public:

	Consumable(std::string _name, std::string _description, int _price, int _weight, Category _category);
};