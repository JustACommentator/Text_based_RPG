#pragma once

#include "Item.h"

class KeyItem : public Item
{
public:

	KeyItem(std::string _name, std::string _description, int _price, int _weight);
};