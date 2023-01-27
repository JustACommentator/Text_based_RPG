#pragma once
#include <string>

enum class Category
{
	ARMOR,
	POTION, // not in use currently
	CONSUMABLE,
	WEAPON,
	ACCESSORY,
	MAGICAL, //maybe?
	KEYITEM,
	HEALTHPOTION,
	MANAPOTION,
	CUREPOTION,
};

class Item
{
protected:

	std::string name;
	std::string description;
	int price;
	int weight;
	Category category;

public:

	Item(std::string _name, std::string _description, int _price, int _weight, Category _category)
		: name(_name), description(_description), price(_price), weight(_weight), category(_category) {};
	virtual const std::string getName() { return name; }
	virtual const int getWeight() { return 0; }
	virtual const Category getCategory() { return category; }
	virtual const std::string getDescription() { return description; }
};   