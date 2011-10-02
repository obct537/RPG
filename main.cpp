// RPG2.cpp : main project file.

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "player.h"
#include "items.h"
#include "enemies.h"
#include "General.h"
#include "combat.h"

using namespace std;


void save(player e)
{
	ofstream Saved;
	Saved.open("save.txt");
	Saved << e.getAttack() << endl;
	Saved << e.getDefense() << endl;
	Saved << e.getHealth() << endl;
	Saved << e.getLevel();

	for (int i = 0; i <= 50; i++)
	{
		Saved << endl << e.getItem(i);
	}
}


int main()
{
	player me;
	player enemy;




	//===================================================================================================
	//======================================this area is for major variables=============================
	//===================================================================================================
	//text strings to be used in center()
	char welcome[40] = "Welcome to INSERT_NAME";
	char welcome2[60] = "would you like to continue an old adventure?";
	char welcome3[40] = "Or start a new one?";



	const int itemNum = 80;
	string listOfItems[itemNum];

	//===================================================================================================
	//===================================================================================================





	center(welcome);
	divider();
	center(welcome2);
	center(welcome3);

	cout << "1)New \n2)Continue" << endl;


	player *me2;
	me2 = &me;


	char x[40];
	//for now, yn is the decision variable, its to be used whenever a choice has to be made
	//looking into a way to make decisions without a variable, so as to avoid scope/redundancy issues
	//considering making a global decision function with a private var to do this
	int yn;
	cin >> yn;

	nmeType Ogre;
	Ogre.setAttack(3);
	Ogre.setDefense(6);
	Ogre.setHealth(10);
	Ogre.setName("Ogre");
	Ogre.addDrop(1,2);

    nmeType *Ogre2;
	Ogre2 = &Ogre;


	if  (yn == 1)
	{
	me.chargen();
	}
	else if (yn == 2)
	{
		me.load();
	}


	cout << "Health: " << me.getHealth() << endl;
	cout << "Attack: " << me.getAttack() << endl;
	cout << "Level: " << me.getLevel() << endl;
	cout << "Defense: " << me.getDefense() << endl;



    me.endFight(encounter(me2, enemy, Ogre2));

	itemz stuff[itemNum];

	stuff[2].setName("something");
	stuff[1].setName("something else");

	itemz *stuff2[itemNum];
	stuff2[itemNum] = &stuff[itemNum];

	//setItemList(itemNum, listOfItems, stuff2);

	me.addItem(1);
	me.listItems(stuff2);



	save(me);
	cout << endl << "press any key to continue...\n";
	cin >> x;
    return 0;
}
