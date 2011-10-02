#include <iostream>
#include <string>
//#include "stdafx.h"
#include "items.h"

using namespace std;


double itemz::getArmRate()
{
	return armRate;
}

string itemz::getName()
{
	return name;
}

double itemz::getWepRate()
{
	return wepRate;
}

int itemz::getType()
{
	return type;
}

double itemz::getValue()
{
	return value;
}

void itemz::setName(string e)
{
	name = e;
}


