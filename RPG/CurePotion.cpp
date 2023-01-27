#include "CurePotion.h"

using namespace std;

CurePotion::CurePotion(std::string _name, string _description, int _price, int _weight, std::list<StatusEffect> _statuslist) :
	Consumable(_name, _description, _price, _weight, Category::MANAPOTION)
{
}