#include "Inventory.h"
#include "Utility.h"
#include <iostream>
#include "Item.h"
#include "ItemID.h"

using namespace std;

Inventory::Inventory()
{
	contentMap = new map<int, int>;
}

const void Inventory::print()
{
	util::fast.startThread();
	cout << endl;

	util::fast << "1) POTIONS & CONSUMABLES\n"
		<< "2) ACCESSORIES\n"
		<< "3) WEAPONS\n"
		<< "4) ARMORS\n"
		<< "5) KEY ITEMS\n"
		<< "6) EVERYTHING\n";

	cout << endl;

	Category cat;

	bool validInput = false;
	bool printAll = false;

	int input;
	do
	{
		cin >> input;
		cin.clear();
		cin.ignore(1000, '\n');

		validInput = true;

		switch (input)
		{
		case 1:
			cat = Category::CONSUMABLE;
			break;
		case 2:
			cat = Category::ACCESSORY;
			break;
		case 3:
			cat = Category::WEAPON;
			break;
		case 4:
			cat = Category::ARMOR;
			break;
		case 5:
			cat = Category::KEYITEM;
			break;
		case 6:
			printAll = true;
			break;
		default:
			validInput = false;
		}

		if (!validInput)
		{
			util::slow.startThread();
			util::slow << "\nSomething seems to have gone wrong, Adventurer, please check your inputs and try again\n\n";
			util::slow.StopThread();
		}
	} while (!validInput);

	cout << endl;

	//TODO: if item is equipped, display small star behind item

	if (printAll)
	{
		for (const auto [key, value] : *contentMap)
		{
			util::fast << "\t" << itemid::id[key].getName();
			if (value > 1)
				util::fast << "   x" << value;
			util::fast << "\n";
		}
	}
	else
	{
		for (const auto [key, value] : *contentMap)
		{
			if (itemid::id[key].getCategory() == cat) // <- doesn't work anymore with the new inheritance system => FIX!
			{
				util::fast << "\t" << itemid::id[key].getName();
				if (value > 1)
					util::fast << "   x" << value;
				util::fast << "\n";
			}
		}
	}

	cout << endl;

	util::fast.StopThread();
}

void Inventory::addItem(int id, int amount)
{
	if (contentMap->find(id) == contentMap->end()) // item not found
	{
		contentMap->insert(pair<int, int>(id, amount));
	}
	else // item found
	{
		contentMap->at(id) += amount;
	}
}
