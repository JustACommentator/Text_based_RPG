#include "ManaPotion.h"

using namespace std;

ManaPotion::ManaPotion(std::string _name, string _description, int _price, int _weight, int _amount) :
	Consumable(_name, _description, _price, _weight, Category::MANAPOTION)
{
	amount = _amount;
}