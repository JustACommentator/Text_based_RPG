#include "Armor.h"

using namespace std;

Armor::Armor(string _name, std::string _description, int _price, int _weight, int _defense) :
	Equippable(_name, _description, _price, _weight, Category::ARMOR)
{
	defense = _defense;
}