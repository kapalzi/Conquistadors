#include "stdafx.h"
#include "BuildersTeam.h"

BuildersTeam::BuildersTeam()
{
}

int BuildersTeam::dailyHunger()
{
	int neededFood = 0;
	for each (Builder* i in buildersPack)
	{
		i->setHunger(-30);
		neededFood += 30;
	}
	return neededFood;
}

int BuildersTeam::dailyEating(int needed, int stored)
{
	if (needed <= stored)
	{
		for each (Builder* i in buildersPack)
		{
			i->setHunger(30);
		}
		return needed;
	}
	else
	{
		for each (Builder *i in buildersPack)
		{
			if (stored >= 30)
				i->setHunger(30);
			stored -= 30;
		}
	}
}

void BuildersTeam::builderDie(int d)
{
	buildersPack.erase(buildersPack.begin(), buildersPack.begin() + d);
}

void BuildersTeam::isBuilderDead()
{
	int deaths = 0;
	for each (Builder* i in buildersPack)
		//for (int i = 0; i < buildersPack.size(); i++)
	{

		if (i->getHunger() <= 0)
		{
			deaths++;
		}
	}
	builderDie(deaths);
}

int BuildersTeam::rebuildSettlement(int condition)
{
	if (condition==1000) return 0;
	if (buildersPack.empty()) return 0;
	int neededRepairs = 1000 - condition;
	int doneRepairs = neededRepairs;
	for each (Builder *i in buildersPack)
	{
		if (i->getTired() < 6 && doneRepairs>0)
		{
			doneRepairs -= 20;
			i->setTired(3);
		}
	}
	if (doneRepairs == 0) return neededRepairs;
	else return neededRepairs - doneRepairs;
}