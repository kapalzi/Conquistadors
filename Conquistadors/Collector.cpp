#include "stdafx.h"
#include "Collector.h"


Collector::Collector(int health, int hunger, int backpackCapacity)
	:Human(health, hunger), backpackCapacity(backpackCapacity)
{
	collectors.insert(collectors.begin(), 20, new Collector());
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

void Collector::collectorsGoOut()
{
	srand(time(NULL));
		if (collectors.empty()) return;

		int l = (rand() % (3 - 1 + 1) + 1);
		for (int i = 0; i < collectors.size(); i++)
		{
			collectors[i]->clearBackpack();
			for (int j = 0; j < l; j++)
			{
				int r = (rand() % (100 - 1 + 1) + 1);
				if (r % 2 == 0)
				{
					collectors[i]->foodFound();
				}
				else if (r % 11 == 0)
				{
					collectors[i]->treasureFound();
				}
			}
		}
}

int Collector::collectorsComeBackWithFood()
{
	if (collectors.empty()) return 0;

	int foodTransport = 0;

	for (int i = 0; i < collectors.size(); i++)
	{
		foodTransport += collectors[i]->getFoundFood();
	}
	return foodTransport;
}

int Collector::collectorsComeBackWithTreasure()
{
	if (collectors.empty()) return 0;

	int treasureTransport = 0;

	for (int i = 0; i < collectors.size(); i++)
	{
		treasureTransport += collectors[i]->getFoundTreasure();
	}
	return treasureTransport;
}

void Collector::collectorsWereAttacked()
{
	int	r = random(1, 10);
	if (r == 7) //zaatakowani czy nie
	{
		int r = random(1, 5);

		for (int i = collectors.size(); i >= r; i--)
		{
			delete collectors[i];
			collectors.erase(collectors.end() - 1);
		}
	}
	else return;
}