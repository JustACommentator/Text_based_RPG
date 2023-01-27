#include <iostream>
#include <string>
#include <Windows.h>
#include "Utility.h"
#include <list>
#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Inventory.h"
#include "ItemID.h"

using namespace std;


int main()
{
	string choice;  

	do
	{
		do
		{
			getline(cin, choice);
			choice.erase(remove(choice.begin(), choice.end(), ' '), choice.end());

		} while (choice != "cancel" && choice != "text" && choice != "inventory");

		if (choice == "text")
		{
			util::slow.startThread();
			const string text = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua.At vero eos et accusam et justo duo dolores et ea rebum.Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua.At vero eos et accusam et justo duo dolores et ea rebum.Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.";

			util::slow << text;
			cout << endl;
			util::slow << text;
			util::slow << text;
			util::slow << text;
			util::slow << text;
			cout << endl << endl;

			util::slow.StopThread();

			util::slow << "Kurze Pause, geht gleich weiter!!!!!!!!!!";

			util::slow.startThread();

			cout << endl << endl;
			util::slow << text;
			util::slow << text;
			util::slow << text;
			util::slow << text;
			cout << endl;

			util::slow.StopThread();
		}
		else if (choice == "inventory")
		{
			Inventory* inv = new Inventory();

			inv->addItem(0);
			inv->addItem(1, 13);
			inv->addItem(2);
			inv->addItem(3);
			inv->addItem(4);
			inv->addItem(5, 21);
			inv->addItem(6, 5);
			inv->addItem(6, 3);

			inv->print();
		}
	} while (choice != "cancel");

	std::system("PAUSE");

	return 0;
}

//TODO: MAYBE Replace list pointers with new empty lists (no pointers)