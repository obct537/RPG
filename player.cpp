#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
//#include "stdafx.h"
#include "player.h"

using namespace std;

void player::setHealth(double e)
{
	health = e;
}

void player::setAttack(double e)
{
	att = e;
}

void player::setDefense(double e)
{
	def = e;
}

void player::setLevel(double e)
{
	lvl = e;
}

double player::getHealth()
{
	return health;
}

double player::getAttack()
{
	return att;
}

double player::getDefense()
{
	return def;
}

double player::getLevel()
{
	return lvl;
}

string player::getName()
 {
	 return name;
 }

void player::chargen()
{
	health = 15;
	att = 5;
	def = 5;
	lvl = 1;

	for (int i = 0; i < 50; i++)
	{
		inven[i] = 0;
	}

}

void player::load()
{
	std::ifstream loaded;
	loaded.open("save.txt",ios::in);
    loaded >> att;
	loaded >> def;
	loaded >> health;
	loaded >> lvl;

	for (int i = 0; i < 50; i++)
	{
		loaded >> inven[i];
	}
}

void player::addItem(int e)
{
	int i = 0;
	int q;

    /*int size;
    size=sizeof inven/sizeof(int);
    cout << size;*/
	do
	{
		if ( inven[i] == 0 )
		{
			inven[i] = e;
			q = 1;
		}
		i++;
	} while ( q != 1 );

}

void player::endFight(double e)
{
	health = e;
}

void player::listItems(itemz *e[])
{
	int i = 0;
	int q;


	do
	{
		if ( inven[i] != 0 )
		{
			int num = inven[i];
			cout << endl << "num: " << i << inven[i];// << " " << e[num]->getName();
			i++;
		}
		else if ( inven[i] == 0 )
		{
			q = 1;
		}
	} while ( q != 1 );
}

int player::getItem(int e)
{
	return inven[e];
}

int player::getItems()
{
    return sizeof(inven);
}
