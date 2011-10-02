//#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include "items.h"

using namespace std;

void center(char e[])
{
	int outputLen = 40;
	int midpt = outputLen - ( strlen(e) / 2 );

	for( int i = 0; i <= midpt; i++)
	{
	    cout << " ";
	}
	cout << e << endl;
}

void divider()
{

	char div[50] = ".:*#*:._.:*#*:._.:*#*:._.:*#*:._.:*#*:._";
	cout << div << div << endl;
}

/*void setItemList(int e, string b[], itemz *z[])
{
	for (int i = 0; i <= e; i++)
	{
		b[i] = z[i]->getName();
	}
}*/
