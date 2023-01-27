#include "Equippable.h"
using namespace std;

Equippable::Equippable(string _name, string _description, int _price, int _weight, Category _category) :
	Item(_name, _description, _price, _weight, _category) {}