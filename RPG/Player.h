#pragma once

#include "Entity.h"
#include "Quest.h"
#include <list>

class Player : public Entity
{
private:

	int currentXP;
	int XPTillNext;
	int money;
	std::list<Quest*>* questList;

public:

	Player(std::string);
	bool pay(int amount);
	void earn(int amount);
	bool checkLevelUp();
	void levelUp();
	const int calculateXP();
	void kill();
	void turn(std::list<Entity*> allies, std::list<Entity*> enemies);
};