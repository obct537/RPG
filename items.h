#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED

#include <iostream>
#include <string>
#include <cmath>
//#include "stdafx.h"

using namespace std;

class itemz
{
private:
	string name;
	double value;
	//to define what it is, wep, armor, item
	int type;
	double wepRate;
	double armRate;

public:
    void buildItemList(int);
	string getName();
	double getValue();
	int getType();
	double getWepRate();
	double getArmRate();
	void setName(string);
};






#endif
