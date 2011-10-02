#ifndef ENEMIES_H_INCLUDED
#define ENEMIES_H_INCLUDED

#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
//#include "stdafx.h"
#include <cstdlib>

using namespace std;

class nmeType
{
private:
	double health;
	double att;
	double def;
	double exp;
	string name;
	int drops[2];
	double wepRate;
	double armRate;

public:

	double getHealth();
	double getAttack();
	double getDefense();
	string getName();
	int getWep(int);

	void setHealth(double);
	void setAttack(double);
	void setDefense(double);
	void setName(string);
	void setArmRate(double);
	void setWepRate(double);
	void addDrop(int, int);

};

#endif
