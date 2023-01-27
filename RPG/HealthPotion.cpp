#include "HealthPotion.h"

using namespace std;

HealthPotion::HealthPotion(string _name, string _description, int _price, int _weight, int _amount) :
	Consumable(_name, _description, _price, _weight, Category::HEALTHPOTION)
{
	amount = _amount;
}