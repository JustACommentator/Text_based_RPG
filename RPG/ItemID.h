#pragma once
#include "Item.h"
#include "Armor.h"
#include "Status.h"
#include "Weapon.h"
#include "KeyItem.h"
#include "Accessory.h"
#include "CurePotion.h"
#include "ManaPotion.h"
#include "HealthPotion.h"

namespace itemid
{
	inline std::list<StatusEffect> statuslist1 { StatusEffect::BURNING };

	inline Armor testArmor("testArmor", "testDescription 1", 100, 20, 20);
	inline ManaPotion testManaPotion("testManaPotion", "testDescription 2", 100, 2, 50);
	inline Weapon testWeapon("testWeapon", "testDescription 3", 100, 20, 20);
	inline KeyItem testKeyItem("testKeyItem", "testDescription 4", 100, 5);
	inline HealthPotion testHealthPotion("testHealthPotion", "testDescription 5", 100, 2, 25);
	inline Accessory testAccessory("testAcessory", "testDescription 6", 100, 20);
	inline CurePotion testCurePotion("testCurePotion", "testDescription 7", 100, 2, statuslist1);


	inline Item id[7] { testArmor, testManaPotion, testWeapon, testKeyItem, testAccessory, testHealthPotion, testCurePotion };
	
	
}