#include "stdafx.h"
#include "Settlement.h"

Settlement::Settlement(int condition, int storedFood, int storedTreasure, int simulationTime) 
	:condition(condition),storedFood(storedFood),storedTreasure(storedTreasure),simulationTime(simulationTime)
{

}

int Settlement::howManyNewCollectorsCome(int c)
{
		while (storedTreasure > 10)
		{
			if (c == 5) return c;
			if (storedTreasure > 10)
			{
				c++;
				storedTreasure -= 10;
			}
		}
		return c;
}
int Settlement::howManyNewSoldiersCome(int s)
{
		while (storedTreasure > 10)
		{
			if (s == 5) return s;
			if (storedTreasure > 10)
			{
				s++;
				storedTreasure -= 10;
			}
		}
		return s;
}
int Settlement::howManyNewBuildersCome(int b)
{

		while (storedTreasure > 10)
		{
			if (b == 5) return b;
			if (storedTreasure > 10)
			{
				b++;
				storedTreasure -= 10;
			}
		}
		return b;
}

