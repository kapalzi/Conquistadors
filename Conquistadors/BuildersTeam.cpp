#include "stdafx.h"
#include "BuildersTeam.h"

BuildersTeam::BuildersTeam()
{
}


BuildersTeam::~BuildersTeam()
{
}

int BuildersTeam::dailyHunger()
{
	int neededFood = 0;
	for each (Builder* i in buildersPack)
	{
		i->setHunger(-20);
		neededFood += 20;
	}
	return neededFood;
}

int BuildersTeam::dailyEating(int needed, int stored)
{
	if (needed <= stored)
	{
		for each (Builder* i in buildersPack)
		{
			i->setHunger(20);
		}
		return needed;
	}
	else
	{
		int ration = stored / buildersPack.size();
		for each (Builder* i in buildersPack)
		{
			i->setHunger(ration);
		}
		return ration * buildersPack.size();
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
