#pragma once

#include <string>
#include <list>
#include "Item.h"
#include "Accessory.h"
#include "Weapon.h"
#include "Status.h"
#include "Armor.h"
#include "Spell.h"
#include "Inventory.h"

class Entity
{
protected:

    int maxHealth;
    int currentHealth;
    int maxMana;
    int currentMana;
    int level;
    int baseAttack;
    int baseMana;
    int baseHealth;
    int baseInitiative;
    int initiative;
    std::string name;
    Weapon* weapon;
    Inventory* inventory;
    Accessory* accessory;
    Status* status;
    Armor* armor;
    std::list<Spell*>* knownSpells;
    bool alive;

public:

    Entity(std::string _name, int _level, int _baseAttack, int _baseHealth, int _baseMana, int _baseInitiative,
        Armor* _armor, Weapon* _weapon, Inventory* _inventory, Accessory* _accessory, Status* _status, std::list<Spell*>* _knownSpells);

    virtual void nothing() {};

    const int calculateHealth();
    const int calculateMana();
    const int calculateInitiative() { return baseInitiative + level - 1; }
    const int initiativeWeight();
    const int getHealth() { return currentHealth; }
    bool heal(int amount);
    bool damage(int amount);
    virtual void kill() { alive = false; }
    void revive() { alive = true; currentHealth = 1; }
    void fullHeal() { currentHealth = maxHealth; }

    std::string getName() { return name; }
};