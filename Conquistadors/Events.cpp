#include "stdafx.h"
#include "Events.h"

Settlement newSettlement;
collectorsTeam collectors;
BuildersTeam builders;
SoldiersTeam soldiers;

Events::Events()
{
}

void Events::addCollectors(int l)
{
	for (int i = 0; i < l; i++)
	{
		collectors.collectorsPack.insert(collectors.collectorsPack.end(), new Collector());
	}
}

void Events::addBuilders(int l)
{
	for (int i = 0; i < l; i++)
	{
		builders.buildersPack.insert(builders.buildersPack.end(), new Builder());
	}
}

void Events::addSoldiers(int l)
{
	for (int i = 0; i < l; i++)
	{
		soldiers.soldiersPack.insert(soldiers.soldiersPack.end(), new Soldier());
	}
}

void Events::startSimulation()
{
		srand(time(NULL));

		addCollectors(20);
		addBuilders(20);
		addSoldiers(40);

		int day = 1;
		while (newSettlement.isAlive)
		{
			if (day % 30 == 0)
			{
				int c = 0;
				while (newSettlement.getStoredTreasure() > 10)
				{
					addCollectors(newSettlement.howManyNewCollectorsCome(0));
					addSoldiers(newSettlement.howManyNewSoldiersCome(0));
					addBuilders(newSettlement.howManyNewBuildersCome(0));
					c++;
				}
				if (c != 0)
					cout << c * 3 << " new people came!" << endl;
			}
			if (collectors.collectorsPack.size() != 0 || soldiers.soldiersPack.size() != 0 || builders.buildersPack.size() != 0)
			{
				if (day % 7 == 0) builders.resetTired();
				collectors.collectorsGoOut();
				collectors.collectorsWereAttacked();
				newSettlement.setCondition(builders.rebuildSettlement(newSettlement.getCondition()));
				newSettlement.setStoredFood(collectors.collectorsComeBackWithFood());
				newSettlement.setStoredTreasure(collectors.collectorsComeBackWithTreasure());
				newSettlement.setStoredFood(-collectors.dailyEating(collectors.dailyHunger(), newSettlement.getStoredFood()));
				newSettlement.setStoredFood(-soldiers.dailyEating(soldiers.dailyHunger(), newSettlement.getStoredFood()));
				newSettlement.setStoredFood(-builders.dailyEating(builders.dailyHunger(), newSettlement.getStoredFood()));
				collectors.isCollectorDead();
				soldiers.isSoldierDead();
				builders.isBuilderDead();
				newSettlement.setCondition(-2 * soldiers.indiansAttack(day));
				newSettlement.checkCondition(newSettlement.getCondition());

				cout << "Day: " << day << endl << "Settlement condition: " << newSettlement.getCondition() << "/1000" << endl << "Number of Collectors: " << collectors.collectorsPack.size() << endl << "Number of Builders: " << builders.buildersPack.size() << endl << "Number of Soldiers: " << soldiers.soldiersPack.size() << endl << "Food in settlement: " << newSettlement.getStoredFood() << endl << "Treasures in settlement: " << newSettlement.getStoredTreasure() << endl << endl << endl;
			}
			day++;
		}
		getch();
}




