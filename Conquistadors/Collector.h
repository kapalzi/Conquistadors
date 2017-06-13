#pragma once
#include "Human.h"
#include <vector>
#include "Settlement.h"
#include <ctime>
using namespace std;
class Collector : public Human
{
	int backpackCapacity;
	int foundFood = 0;
	int foundTreasure = 0;
public:
	Collector(int health = 100, int hunger = 100, int backpackCapacity = 25);
	~Collector();

	int getBackpackCapacity() { return backpackCapacity; }
	int getFoundFood() { return foundFood; }
	int getFoundTreasure() { return foundTreasure; }

	void setBackpackCapacity(int backpackCapacity) { this->backpackCapacity = backpackCapacity; }
	void setFoundFood(int foundFood) { this->foundFood = foundFood; }
	void setFoundTreasure(int foundTreasure) { this->foundTreasure = foundTreasure; }

	void foodFound();
	void treasureFound();
	void clearBackpack() { setBackpackCapacity(0); }
};


