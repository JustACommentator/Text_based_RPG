#include "Player.h"
#include "Utility.h"
#include <Windows.h>

using namespace std;

Player::Player(string _name, BaseArea* _currentArea, CurrentState _currentState) :
	Entity(_name, 1, 20, 100, 100, 100, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr)
{
	currentState = _currentState;
	currentArea = _currentArea;
	currentXP = 0;
	XPTillNext = 1000;
	money = 10;
	questList = new list<Quest*>();
	inventory = new Inventory();
	knownSpells = new list<Spell*>();
}

bool Player::pay(int amount)
{
	if (money < amount)
		return false;
	money -= amount;
	return true;
}

void Player::earn(int amount)
{
	money += amount;
}

bool Player::checkLevelUp()
{
	if (currentXP >= XPTillNext || level >= 100)
	{
		if (level >= 100)
			currentXP = 0;
		return false;
	}

	levelUp();
	return true;
}

void Player::levelUp()
{
	int overflow = currentXP - XPTillNext;
	level++;
	XPTillNext = calculateXP();
	currentXP = overflow;

	int healthDiff = maxHealth - currentHealth;
	maxHealth = calculateHealth();
	currentHealth = maxHealth - healthDiff;

	checkLevelUp();
}

const int Player::calculateXP()
{
	double base = 1000;
	for (int i = 1; i < level; i++)
		base *= 1.1;
	return int (base);
}

void Player::kill()
{
	alive = false;
	currentState = IN_OVERWORLD;

	cout << endl << endl << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		util::slow << ".";
		Sleep(350);
	}

	util::slow << "It seems like your adventure has come to an abrupt end, Adventurer. May thy light shine again... ";
	while (true)
		if (GetKeyState(' ') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
			break;

	//TODO: go back to respawn
}

void Player::turn(list<Entity*> allies, list<Entity*> enemies)
{
	util::fast << "What would you like to do?\n"
		"1) Attack\n"
		"2) Spell\n"
		"3) Inventory\n"
		"4) Flee\n"
		"5) Info\n";
	int action = 0;

	bool validInputAction = false;

	int inputAction = 0;
	do
	{
		cin >> inputAction;
		cin.clear();
		cin.ignore(1000, '\n');

		validInputAction = true;

		switch (inputAction)
		{
		case 1:
			//select an enemy, then player->attack(enemy)
			break;
		case 2:
			//select a spell, then see above
			break;
		case 3:
			//print inventory, then select item, then, depending on item, select target
			break;
		case 4:
			//check if player can flee. If yes, stop combat
			break;
		case 5:
		{
			int count = 0;
			util::fast.startThread();
			for (Entity* e : allies)
			{
				util::fast << ++count << ") " << e->getName();
			}
			for (Entity* e : enemies)
			{
				util::fast << ++count << ") " << e->getName();
			}
			bool validInputInfo = false;

			//check info

			break;
		}
		default:
			validInputAction = false;
		}

		if (!validInputAction)
		{
			util::slow.startThread();
			util::slow << "\nSomething seems to have gone wrong, Adventurer, please check your inputs and try again\n\n";
			util::slow.StopThread();
		}
	} while (!validInputAction);
}
