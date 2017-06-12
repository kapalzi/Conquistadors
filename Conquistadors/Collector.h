#pragma once
#include "Human.h"
#include <vector>
#include "Settlement.h"
using namespace std;
class Collector : public Human
{
	int backpackCapacity;
	int foundFood = 0;
	int foundTreasure = 0;
	static int collectorCounter;

public:
	Collector(int health = 100, int hunger = 100, int backpackCapacity = 25);
	~Collector();

	 vector<Collector*>collectors;

	static int getCollectorCounter() { return collectorCounter; }
	int getBackpackCapacity() { return backpackCapacity; }
	int getFoundFood() { return foundFood; }
	int getFoundTreasure() { return foundTreasure; }

	void setBackpackCapacity(int backpackCapacity) { this->backpackCapacity = backpackCapacity; }
	void setFoundFood(int foundFood) { this->foundFood = foundFood; }
	void setFoundTreasure(int foundTreasure) { this->foundTreasure = foundTreasure; }

	void foodFound();
	void treasureFound();
	void clearBackpack() { setBackpackCapacity(0); }

	 void collectorsGoOut();
	 int collectorsComeBackWithFood();
	 int collectorsComeBackWithTreasure();
	 void collectorsWereAttacked();
};

