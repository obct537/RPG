#include <iostream>
#include <cmath>
#include <cstdlib>
//#include "stdafx.h"
#include <string>
#include "enemies.h"

using namespace std;

void nmeType::setHealth(double e)
{
	health = e;
}

void nmeType::setAttack(double e)
{
	att = e;
}

void nmeType::setDefense(double e)
{
	def = e;
}

void nmeType::setName(string e)
{
	name = e;
}

void nmeType::setArmRate(double e)
{
	armRate = e;
}

void nmeType::setWepRate(double e)
{
	wepRate = e;
}

double nmeType::getAttack()
{
	return att;
}

double nmeType::getDefense()
{
	return def;
}

double nmeType::getHealth()
{
	return health;
}

string nmeType::getName()
{
	return name;
}

void nmeType::addDrop(int a, int b)
{
		drops[0] = a;
		drops[1] = b;
}

int nmeType::getWep(int e)
{
	return drops[e];
}


