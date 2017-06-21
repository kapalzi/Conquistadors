#pragma once
#include <vector>


using namespace std;
class Settlement 
{
	int storedFood;
	int storedTreasure;
	int condition;

public:
	Settlement(int condition = 1000, int storedFood = 3600, int storedTreasure = 0);
	bool isAlive = 1;
	int getStoredFood() { return storedFood; }
	int getStoredTreasure() { return storedTreasure; }
	int getCondition() { return condition; }
	
	void setStoredFood(int a) { this->storedFood += a; }
	void setStoredTreasure(int a) { this->storedTreasure += a; }
	void setCondition(int a) { this->condition += a; }
	void checkCondition(int condition);

	int howManyNewCollectorsCome(int c);
	int howManyNewSoldiersCome(int s);
	int howManyNewBuildersCome(int b);


};

