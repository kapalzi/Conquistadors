#include "stdafx.h"
#include "SoldiersTeam.h"
using namespace std;

SoldiersTeam::SoldiersTeam()
{
}


SoldiersTeam::~SoldiersTeam()
{
}

int SoldiersTeam::dailyHunger()
{
	int neededFood = 0;
	for each (Soldier* i in soldiersPack)
	{
		i->setHunger(-20);
		neededFood += 20;
	}
	return neededFood;
}

int SoldiersTeam::dailyEating(int needed, int stored)
{
	if (needed <= stored)
	{
		for each (Soldier* i in soldiersPack)
		{
			i->setHunger(20);
		}
		return needed;
	}
	else
	{
		int ration = stored / soldiersPack.size();
		for each (Soldier* i in soldiersPack)
		{
			i->setHunger(ration);
		}
		return ration * soldiersPack.size();
	}
}

void SoldiersTeam::soldierDie(int d)
{
	soldiersPack.erase(soldiersPack.begin(), soldiersPack.begin() + d);
}

void SoldiersTeam::isSoldierDead()
{
	int deaths = 0;
	for each (Soldier* i in soldiersPack)
		//for (int i = 0; i < soldiersPack.size(); i++)
	{

		if (i->getHunger() <= 0)
		{
			deaths++;
		}
	}
	soldierDie(deaths);
}