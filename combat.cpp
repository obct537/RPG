//#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include "player.h"
#include "enemies.h"


double encounter(player *a, player b, nmeType *c)
{

	double ran;
	int ran2;
	double dMod = 8;
	double point = b.getAttack();

	int yn;
	int opt;

	double damage;
	double defense;

	//these numbers are just placeholders until we get the weapon/drop system functional
	//and yes...they are obscenely unbalanced
	double wepEff1 = 250;
	double armRate2 = 250;

	//===========================================================
	//           important to remember in the future
	//
	//	random number system ripped off some website i forgot to credit

	time_t now;
    time(&now);
    srand(now);
    rand();

	do
	{
	ran = (rand() % 10 + 1 );
	ran -= dMod;
	} while ( ran < 1 );


	ran2 = (rand() % 2 );

	//===========================================================


	//creates base for multiplication
	b.chargen();

	b.setLevel(a->getLevel() + ran);
	cout << b.getLevel() << endl;


	for (int i = 1; i <= b.getLevel(); i++)
	{
		double plusAtt = ceil(b.getAttack() + (b.getAttack() * (.05 + .005)));
		double plusHea = ceil(b.getHealth() + (b.getHealth() * (.10 + .005)));
		double plusDef = ceil(b.getDefense() + (b.getDefense() * (.05 + .005)));

		b.setDefense(plusDef);
		b.setAttack(plusAtt);
		b.setHealth(plusHea);
	}



	cout << endl << "You've encountered a level " << b.getLevel() << " " << c->getName();
	cout << endl << "Health: " << b.getHealth();
	cout << endl << "Attack: " << b.getAttack();
	cout << endl << "Defense: " << b.getDefense();
	cout << endl << "1)Attack! \n2)Run Away!\n\n";
	cin >> yn;


	if (yn == 1)
	{
		cout << endl << "mkay\n";
	}
	else if (yn == 2)
	{
		cout << endl << "You got away.";
		exit(EXIT_SUCCESS);
	}
	else
	{
		cout << endl << "you suck";
	}

	opt = 1;


	do
	{

		//this is all simple math, just read through it

		if ( opt == 1 )
		{
			damage = ((a->getAttack() * .25) + (a->getLevel() * .25 ) + (wepEff1 * .5));
			defense = ((b.getDefense() * .25) + (b.getLevel() * .25 ) + (armRate2 * .5));

			//Bethesda damage engine
			cout << "Damage: " << ceil((damage * damage) / (damage + defense)) << endl;
			b.setHealth(b.getHealth() - floor((damage * damage) / (damage + defense)));
			cout << "Enemy health: " << b.getHealth() << endl;

			opt++;
		}

		else if ( opt == 2 )
		{
			damage = ((b.getAttack() * .25) /*+ (b.getLevel() * .25 )*/ + (wepEff1 * .5));
			defense = ((a->getDefense() * .25) + /*(a.getLevel() * .25 )*/ + (armRate2 * .5));

			//Bethesda damage engine
			cout << "Damage: " << ceil((damage * damage) / (damage + defense)) << endl;
			a->setHealth(a->getHealth() - ceil((damage * damage) / (damage + defense)));
			cout << "Your health: " << a->getHealth() << endl;
			opt = 1;
		}

	} while ( a->getHealth() > 0 && b.getHealth() > 0);



	if ( a->getHealth() <= 0)
	{
		cout << endl << "You Died!!!! :( " << endl;
	}
	else if ( b.getHealth() <= 0 )
	{
		cout << endl << "You Win!!!" << endl;
		cout << endl << "drop: " << ran2;
		cout << endl << c->getName() << " dropped a " << c->getWep(ran2);
		a->addItem(c->getWep(ran2));
	}

	return a->getHealth();
}
