#pragma once

#include "Entity.h"
#include "Quest.h"
#include <list>
#include "BaseArea.h"
#include "CurrentState.h"

class Player : public Entity
{
private:

	int currentXP;
	int XPTillNext;
	int money;
	std::list<Quest*>* questList;
	BaseArea* currentArea;
	CurrentState currentState;

public:

	Player(std::string, BaseArea* _currentArea, CurrentState _currentState);
	bool pay(int amount);
	void earn(int amount);
	bool checkLevelUp();
	void levelUp();
	const int calculateXP();
	void kill();
	void turn(std::list<Entity*> allies, std::list<Entity*> enemies);
	void setArea(BaseArea* _currentArea) { currentArea = _currentArea; }
	BaseArea* getArea() { return currentArea; }
	void setCurrentState(CurrentState _currentState) { currentState = _currentState; }
	CurrentState getCurrentState() { return currentState; }
};