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

void clearScreen(int len)
{
    cout << string(len, '\n');
}


/**
cleanInt()

BROKEN

no params

function is made to prompt for user input,
and only allow a valid integer

*/
int cleanInt()
{

    int a;
    char out[10];
    int ch = 0;

    while ((ch = getchar()) != '\n' && ch != EOF);

    do
    {
        a = NULL;

        scanf("%d", &a);
        cout << a << endl;
        sprintf(out, "%d", a);

        //Stolen off the internet. This clears out STDIN
        //in case scanf fails.
        while ((ch = getchar()) != '\n' && ch != EOF);

        if( a == NULL )
        {
            cout << "Invalid entry" << endl;
        }

    }while (!isdigit(out[0]));

    return a;
}

/*void setItemList(int e, string b[], itemz *z[])
{
	for (int i = 0; i <= e; i++)
	{
		b[i] = z[i]->getName();
	}
}*/
