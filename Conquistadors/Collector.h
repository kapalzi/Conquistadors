#pragma once
#include "Human.h"
class Collector : public Human
{
	int backpackCapacity;
	int foundFood;
	int foundTreasure;
	static int collectorCounter;
public:
	Collector(int health = 100, int hunger = 100, int backpackCapacity = 100);
	~Collector();
	
	static int getCollectorCounter() { return collectorCounter; }
	int getBackpackCapacity() { return backpackCapacity; }
	int getFoundFood() { return foundFood; }
	int getFoundTreasure() { return foundTreasure; }

	void setBackpackCapacity(int backpackCapacity) { this->backpackCapacity = backpackCapacity; }
	void setFoundFood(int foundFood) { this->foundFood = foundFood; }
	void setFoundTreasure(int foundTreasure) { this->foundTreasure = foundTreasure; }

};

