#include "stdafx.h"
#include "Settlement.h"



Settlement::Settlement(int condition = 100, int storedFood = 3600, int storedTreasure = 0, int simulationTime = 1) 
	:condition(condition),storedFood(storedFood),storedTreasure(storedTreasure),simulationTime(simulationTime)
{


	soldiers.insert(soldiers.begin(), 40, new Soldier());
	//soldiers[5]->getAttack;
	collectors.insert(collectors.begin(), 20, new Collector());
	builders.insert(builders.begin(), 20, new Builder());
	
}
