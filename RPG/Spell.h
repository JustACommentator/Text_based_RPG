#pragma once
#include <string>

enum SpellType
{
	HEALING,
	DAMAGE,
	BUFF,
	DEBUFF
};

class Spell
{
protected:

	std::string name;
	SpellType type;
};