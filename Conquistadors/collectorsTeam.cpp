#include "stdafx.h"
#include "collectorsTeam.h"
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

collectorsTeam::collectorsTeam()
{

}

void collectorsTeam::collectorsGoOut()
{
	if (collectorsPack.empty()) return;
	int l = random(1, 3);
	for each (Collector* i in collectorsPack)
	{
		i->clearBackpack();
		for (int j = 0; j < l; j++)
		{
			int r = random(1, 100);
			if (r % 99 == 0)
			{
				i->treasureFound();
			}
			if (r % 3 == 0)
			{
				i->foodFound();
			}
		}
	}
}

int collectorsTeam::collectorsComeBackWithFood()
{
	if (collectorsPack.empty()) return 0;

	int foodTransport = 0;

	for (int i = 0; i < collectorsPack.size(); i++)
	{
		foodTransport += collectorsPack[i]->getFoundFood();
	}
	return foodTransport;
}

int collectorsTeam::collectorsComeBackWithTreasure()
{
	if (collectorsPack.empty()) return 0;

	int treasureTransport = 0;

	for (int i = 0; i < collectorsPack.size(); i++)
	{
		treasureTransport += collectorsPack[i]->getFoundTreasure();
	}
	return treasureTransport;
}

void collectorsTeam::collectorsWereAttacked()
{
	int	r = random(1, 10);
	if(r%7==0) //zaatakowani czy nie
	{
		int r = random(1, 3);

		if (r > collectorsPack.size())
			r = collectorsPack.size();
		collectorsPack.erase(collectorsPack.begin(), collectorsPack.begin() + r);
		cout << endl<< "Collectors were attacked! " << r << " collectors died ;C" << endl;
	}
	else return;
}

int collectorsTeam::dailyHunger()
{
	int neededFood=0;
	for each (Collector* i in collectorsPack)
	{
		i->setHunger(-30);
		neededFood += 30;
	}
	return neededFood;
}

int collectorsTeam::dailyEating(int needed,int stored)
{
	if (needed <= stored)
	{
		for each (Collector* i in collectorsPack)
		{
			i->setHunger(30);
		}
		return needed;
	}
	else
	{
		for each (Collector* i in collectorsPack)
		{
			if(stored>=30)
			i->setHunger(30);
			stored -= 30;
		}
	}
}

void collectorsTeam::collectorsDie(int d)
{
	collectorsPack.erase(collectorsPack.begin(), collectorsPack.begin() + d);
}

void collectorsTeam::isCollectorDead()
{
	int deaths = 0;
	for each (Collector* i in collectorsPack)
	{

		if (i->getHunger() <= 0)
		{
			deaths++;
		}
	}
	collectorsDie(deaths);
}