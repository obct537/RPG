//#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include "player.h"
#include "enemies.h"

void doDamage(player *user, player *nme)
{
    int opt = 0;
    int armRate2 = 10;
    int wepEff1 = 10;
    player *a;
    player *b;
    string pov;
    do
    {
        if( opt == 0 )
        {
            a = user;
            b = nme;
            pov = "Your";
            opt++;

        }
        else
        {
            a = nme;
            b = user;
            pov = "Enemy";
            opt = 0;
        }


        int damage = ((a->getAttack() * .25) + (a->getLevel() * .25 ) + (wepEff1 * .5));
        int defense = ((b->getDefense() * .25) + (b->getLevel() * .25 ) + (armRate2 * .5));

        //Bethesda damage engine
        cout << "Damage: " << ceil((damage * damage) / (damage + defense)) << endl;
        b->setHealth(b->getHealth() - floor((damage * damage) / (damage + defense)));
        cout << pov << " health: " << b->getHealth() << endl;

    }while( user->getHealth() > 0 && nme->getHealth() > 0 );
}

void genNme(player *a, player *b, double ran)
{

    b->chargen();

	b->setLevel(a->getLevel() + ran);
	cout << b->getLevel() << endl;


	for (int i = 1; i <= b->getLevel(); i++)
	{
		double plusAtt = ceil(b->getAttack() + (b->getAttack() * (.05 + .005)));
		double plusHea = ceil(b->getHealth() + (b->getHealth() * (.10 + .005)));
		double plusDef = ceil(b->getDefense() + (b->getDefense() * (.05 + .005)));

		b->setDefense(plusDef);
		b->setAttack(plusAtt);
		b->setHealth(plusHea);
	}

}

double encounter(player *a, player b, nmeType *c)
{

	double ran;
	int ran2;
	double dMod = 8;

	int yn;

    player *g = &b;
    genNme(a,g, ran);

	//===========================================================
	//           important to remember in the future
	//
	//	random number system ripped off some website i forgot to credit

	time_t now;
    time(&now);
    srand(now);
    rand();

	ran = (rand() % 10 + 1 );
	ran -= dMod;

	ran2 = (rand() % 2 );

	//===========================================================


	cout << endl << "You've encountered a level " << b.getLevel() << " " << c->getName();
	cout << endl << "Health: " << b.getHealth();
	cout << endl << "Attack: " << b.getAttack();
	cout << endl << "Defense: " << b.getDefense();
	cout << endl << "1)Attack! \n2)Run Away!\n\n";
	cin >> yn;

	if (yn == 1)
	{
		cout << endl << "mkay\n";
        doDamage(a, g);
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

