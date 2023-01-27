#include "Weapon.h"

using namespace std;

Weapon::Weapon(string _name, string _description, int _price, int _weight, int _damage) :
	Equippable(_name, _description, _price, _weight, Category::WEAPON)
{
	damage = _damage;
}