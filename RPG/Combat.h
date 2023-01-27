#pragma once
#include "Entity.h"

class Combat
{
private:

	std::list<Entity*> participants;
	std::list<Entity*> enemies;
	std::list<Entity*> allies;
	int enemiesAlive;

public:

	Combat(std::list<Entity*> _participants);
	void killEnemy() { enemiesAlive--; }
};