#include "KeyItem.h"

using namespace std;

KeyItem::KeyItem(string _name, string _description, int _price, int _weight) :
	Item(_name, _description, _price, _weight, Category::KEYITEM)
{
}