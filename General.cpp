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
cleanInt(int)

params:
    Int: allows inputs from 1 to (int)

status: Working, needs more.

Function is made to prompt for user input,
and only allow a valid integer.

Default range is 1 to 2

*/
int cleanInt(int size = 0)
{
    int a;
    int ch = 0;

    //This makes the default range 1-2
    //Usually for the simple yes/no
    if( size == 0 )
    {
        size = 2;
    }

    //Checks if its in the correct number range
    do
    {
        //Checks if its actually an integer
        do
        {
            //Allows for easy looping, plus
            //prevents any overflow from last iteration.
            a = NULL;

            //Reads INT from STDIN.
            scanf("%d", &a);

            //Stolen off the internet. This clears out STDIN
            //in case scanf fails.
            //
            //In the event scanf doesn't execute, it leaves the
            //values in STDIN
            while ((ch = getchar()) != '\n' && ch != EOF);

            if( a == NULL )
            {
                cout << "Invalid entry" << endl;
            }

        }while ( a == NULL );

    }while (a > size || a < 1);

    return a;
}

/*void setItemList(int e, string b[], itemz *z[])
{
	for (int i = 0; i <= e; i++)
	{
		b[i] = z[i]->getName();
	}
}*/
