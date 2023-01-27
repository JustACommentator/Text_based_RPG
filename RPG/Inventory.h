#pragma once

#include <list>
#include <map>
class Item;

class Inventory
{
private:

	std::map<int, int>* contentMap;

public:

	Inventory();
	const void print();
	void addItem(int id, int amount = 1);
};