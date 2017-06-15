#include "stdafx.h"
#include "SoldiersTeam.h"
using namespace std;

SoldiersTeam::SoldiersTeam()
{
}


SoldiersTeam::~SoldiersTeam()
{
}



int::SoldiersTeam::battleResult(int howMany)
{
	for each (Soldier* i in soldiersPack)
	{
		if(howMany>0)
		howMany-=i->combatPointsMeaning(i->getcombatPoints());
		i->setCombatPoints(1);
	}
	if (howMany > 0)
	{
		if (howMany > soldiersPack.size())
		howMany = soldiersPack.size();

		return howMany;
	}
	else
	{
		return random(0, soldiersPack.size())/10;
	}
}

int SoldiersTeam::indiansAttack(int days)
{
	int	r = random(1, 10);
	if (r % 7 == 0)//zaatakowali czy nie
	{
		int howMany;
		if (days < 30)
		{
			howMany = random(15, 30);
			//battleResult(howMany);
		}
		if (days >= 30 && days < 200)
		{
			howMany = random(60, 480);
			//battleResult(howMany);
		}
		if (days >= 200)
		{
			howMany = random(480, 2048);
			if (howMany > 2040)
			{
				howMany = random(2040, 30000);
				//battleResult(howMany);
			}
		}
		soldierDie(battleResult(howMany));
		cout << "Settlement was attacked by " << howMany << " indians" << endl;
		return howMany;
	}
	else return 0;
}

int SoldiersTeam::dailyHunger()
{
	int neededFood = 0;
	for each (Soldier* i in soldiersPack)
	{
		i->setHunger(-30);
		neededFood += 30;
	}
	return neededFood;
}

int SoldiersTeam::dailyEating(int needed, int stored)
{
	if (needed <= stored)
	{
		for each (Soldier* i in soldiersPack)
		{
			i->setHunger(30);
		}
		return needed;
	}
	else
	{
		for each (Soldier* i in soldiersPack)
		{
			if (stored >= 30)
				i->setHunger(30);
			stored -= 30;
		}
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