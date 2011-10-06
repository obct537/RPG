#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
//#include "stdafx.h"
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "items.h"

using namespace std;

class player
{
private:
	double health;
	double att;
	double def;
	double lvl;
	string name;
	double exp;
	int inven[50];

public:
	void setHealth(double);
	void setAttack(double);
	void setDefense(double);
	void setLevel(double);
	void listItems(itemz e[]);
	double getHealth();
	double getAttack();
	double getDefense();
	string getName();
	int getItem(int);
	double getLevel();
	void attack();
	void addItem(int);
	void addExp(double);
	void levelUp();
	void save();
	void load();
	void chargen();
	void endFight(double);
	int getItems();


};


#endif
