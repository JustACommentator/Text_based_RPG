#include "Entity.h"

Entity::Entity(std::string _name, int _level, int _baseAttack, int _baseHealth, int _baseMana, int _baseInitiative,
	Armor* _armor, Weapon* _weapon, Inventory* _inventory, Accessory* _accessory, Status* _status, std::list<Spell*>* _knownSpells)
{
	name = _name;
	level = _level;
	baseAttack = _baseAttack;
	baseHealth = _baseHealth;
	baseMana = _baseMana;
	baseInitiative = _baseInitiative;
	armor = _armor;
	weapon = _weapon;
	inventory = _inventory;
	accessory = _accessory;
	status = _status;
	alive = true;
	knownSpells = _knownSpells;



	maxHealth = calculateHealth();
	currentHealth = maxHealth;

	maxMana = calculateMana();
	currentMana = maxMana;

	initiative = calculateInitiative();
}

const int Entity::calculateHealth()
{
	double calcHealth = double (baseHealth);

	for (int i = 1; i < this->level; i++)
		calcHealth *= 1.02354;


	return int (calcHealth);
}

const int Entity::calculateMana()
{
	double calcMana = double(baseMana);

	for (int i = 1; i < this->level; i++)
		calcMana *= 1.0164;


	return int(calcMana);
}

bool Entity::heal(int amount)
{
	if (currentHealth == maxHealth)
		return false;

	currentHealth += amount;
	if (currentHealth > maxHealth)
		currentHealth = maxHealth;
	return true;
}

bool Entity::damage(int amount)
{
	currentHealth -= amount;
	if (currentHealth <= 0)
	{
		kill();
		return false;
	}
	else
		return true;
}

const int Entity::initiativeWeight()
{
	int ini = calculateInitiative() - armor->getWeight() - weapon->getWeight();

	return (ini > 1 ? ini : 1);
}
