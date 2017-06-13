#pragma once
#include <vector>


using namespace std;
class Settlement
{
	int storedFood;
	int storedTreasure;
	int simulationTime;
	int condition;

public:
	Settlement(int condition = 100, int storedFood = 3600, int storedTreasure = 0, int simulationTime = 1);
	bool isAlive = 1;
	int getStoredFood() { return storedFood; }
	int getStoredTreasure() { return storedTreasure; }
	int getSimulationTime() { return simulationTime; }
	
	void setStoredFood(int a) { this->storedFood += a; }
	void setStoredTreasure(int a) { this->storedTreasure += a; }

	int howManyNewCollectorsCome(int c);
	int howManyNewSoldiersCome(int s);
	int howManyNewBuildersCome(int b);
};

