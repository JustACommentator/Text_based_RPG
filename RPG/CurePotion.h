#pragma once

#include "Consumable.h"
#include "Status.h"
#include <list>

class CurePotion : public Consumable
{
private:

	std::list<StatusEffect> statuslist;

public:

	CurePotion(std::string _name, std::string _description, int _price, int _weight, std::list<StatusEffect> _statuslist);
	const std::list<StatusEffect> getStatusList() { return statuslist; }
};