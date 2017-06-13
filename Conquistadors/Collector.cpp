#include "stdafx.h"
#include "Collector.h"
#include <iostream>

Collector::Collector(int health, int hunger, int backpackCapacity)
	:Human(health, hunger), backpackCapacity(backpackCapacity)
{
}


Collector::~Collector()
{
}

void Collector::foodFound()
{
	if (backpackCapacity + 12 < 0) return;
	this->setFoundFood(this->getFoundFood() + 12);
	this->setBackpackCapacity(getBackpackCapacity() - 12);
}

void Collector::treasureFound()
{
	if (backpackCapacity + 2 < 0) return;
	this->setFoundTreasure(this->getFoundTreasure() + 2);
	this->setBackpackCapacity(getBackpackCapacity() - 2);
}
/*
void Collector::collectorsGoOut()
{
		if (collectorsTeam.empty()) return;
		int l = random(1, 3);
		for (int i = 0; i < collectorsTeam.size(); i++)
		{
			collectorsTeam[i]->clearBackpack();
			for (int j = 0; j < l; j++)
			{
				int r = random(1, 100);
				 if (r % 11 == 0)
				{
					 collectorsTeam[i]->treasureFound();
				}
				
				 if (r % 2 == 0)
				{
					 collectorsTeam[i]->foodFound();
				}
				
			}
		}
}

int Collector::collectorsComeBackWithFood()
{
	if (collectorsTeam.empty()) return 0;

	int foodTransport = 0;

	for (int i = 0; i < collectorsTeam.size(); i++)
	{
		foodTransport += collectorsTeam[i]->getFoundFood();
	}
	return foodTransport;
}

int Collector::collectorsComeBackWithTreasure()
{
	if (collectorsTeam.empty()) return 0;

	int treasureTransport = 0;

	for (int i = 0; i < collectorsTeam.size(); i++)
	{
		treasureTransport += collectorsTeam[i]->getFoundTreasure();
	}
	return treasureTransport;
}

void Collector::collectorsWereAttacked()
{
	int	r = random(1, 10);
	if (0)//(r%7==0) //zaatakowani czy nie
	{
		int r = random(1, 3);

		if (r > collectorsTeam.size())
		r = collectorsTeam.size();
		collectorsTeam.erase(collectorsTeam.begin(), collectorsTeam.begin() + r);
	}
	else return;
}

void Collector::dailyHunger()
{
	//for each (Collector* i in collectors)
	for (int i = 0; i < collectorsTeam.size(); i++)
	{
		this->collectorsTeam[i]->setHunger(20);
	}
}

void Collector::collectorsDie(int d)
{
	collectorsTeam.erase(collectorsTeam.begin(), collectorsTeam.begin()+d);
}

void Collector::isCollectorDead()
{
	int deaths = 0;
	//for each (Collector* i in collectors)
	for (int i = 0; i < collectorsTeam.size(); i++)
	{
		
		if (this->collectorsTeam[i]->getHunger() <= 0)
		{
			deaths++;
		}
	}
	collectorsDie(deaths);
}
*/