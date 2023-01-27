#include "Consumable.h"
using namespace std;

Consumable::Consumable(string _name, string _description, int _price, int _weight, Category _category) :
	Item(_name, _description, _price, _weight, Category::CONSUMABLE)
{
	potionType = _category;
}