// Conquistadors.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#include "stdafx.h"
#include "Settlement.h"
#include <vector>
#include <iostream>
#include <ctime>
#include "collectorsTeam.h"
#include "BuildersTeam.h"
#include "SoldiersTeam.h"
using namespace std;
Settlement newSettlement;
collectorsTeam collectors;
BuildersTeam builders;
SoldiersTeam soldiers;

void addCollectors(int l)
{
	for (int i = 0; i < l; i++)
	{
		collectors.collectorsPack.insert(collectors.collectorsPack.end(), new Collector());
	}
	cout << l<< " new Collectors came!" << endl;
}

void addBuilders(int l)
{
	for (int i = 0; i < l; i++)
	{
		builders.buildersPack.insert(builders.buildersPack.end(), new Builder());
	}
	cout << l << " new Builders came!" << endl;
}

void addSoldiers(int l)
{
	for (int i = 0; i < l; i++)
	{
		soldiers.soldiersPack.insert(soldiers.soldiersPack.end(), new Soldier());
	}
	cout << l << " new Soldiers came!" << endl;
}

int main()
{
	srand(time(NULL));
	
	addCollectors(20);
	addBuilders(20);
	addSoldiers(40);

	int day = 1;
	//while (newSettlement.isAlive)
	while (day < 1000)
	{
		if (day % 15 == 0)
		{
			addCollectors(newSettlement.howManyNewCollectorsCome(0));
			addSoldiers(newSettlement.howManyNewSoldiersCome(0));
			addBuilders(newSettlement.howManyNewBuildersCome(0));
		}

		if (collectors.collectorsPack.size() != 0 || builders.buildersPack.size()!=0 || soldiers.soldiersPack.size()!=0)
		{
			collectors.collectorsGoOut();
			collectors.collectorsWereAttacked();
			newSettlement.setStoredFood(collectors.collectorsComeBackWithFood());
			newSettlement.setStoredTreasure(collectors.collectorsComeBackWithTreasure());
			newSettlement.setStoredFood(-collectors.dailyEating(collectors.dailyHunger(), newSettlement.getStoredFood()));
			collectors.isCollectorDead();

			newSettlement.setStoredFood(-soldiers.dailyEating(soldiers.dailyHunger(), newSettlement.getStoredFood()));
			soldiers.isSoldierDead();

			newSettlement.setStoredFood(-builders.dailyEating(builders.dailyHunger(), newSettlement.getStoredFood()));
			builders.isBuilderDead();
			

			cout << "Day: " << day << endl << "Number of Collectors: " << collectors.collectorsPack.size() <<endl<<"Number of Builders: "<<builders.buildersPack.size() << endl << "Number of Soldiers: " << soldiers.soldiersPack.size() << endl << "Food in settlement: " << newSettlement.getStoredFood() << endl << "Treasures in settlement: " << newSettlement.getStoredTreasure() << endl << endl << endl;
		}
		day++;
	}

	cin >> day;

    return 0;
}

