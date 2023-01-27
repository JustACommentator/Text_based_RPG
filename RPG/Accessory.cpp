#include "Accessory.h"
using namespace std;

Accessory::Accessory(string _name, string _description, int _price, int _weight) :
	Equippable(_name, _description, _price, _weight, Category::ACCESSORY) {}
