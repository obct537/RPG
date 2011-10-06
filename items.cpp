#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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

void itemz::buildItemList(int size)
{
    ifstream itemList;
    itemList.open("items.txt",ios::in);

    string output[size];
    int counter = 0;

    stringstream ss;
    string inp;
    int foo;

    /*while ( getline(cin, inp));
    {
        ss.clear();
        ss.str("");
        ss << itemList;

        while( ss >> foo)
        {
            cout << endl << ss;
        }
    }*/
}


