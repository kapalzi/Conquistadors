#pragma once
#include <vector>
#include "Soldier.h"
#include "Collector.h"
#include "Builder.h"
using namespace std;
class Settlement
{
	int storedFood;
	int storedTreasure;
	int simulationTime;
	int condition;
	vector <Soldier*>soldiers;
	vector<Collector*>collectors;
	vector<Builder*>builders;
public:
	Settlement(int condition = 100, int storedFood = 3600, int storedTreasure = 0, int simulationTime = 1);

};

