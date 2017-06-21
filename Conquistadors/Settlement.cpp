#include "stdafx.h"
#include "Settlement.h"

Settlement::Settlement(int condition, int storedFood, int storedTreasure) 
	:condition(condition),storedFood(storedFood),storedTreasure(storedTreasure)
{

}

int Settlement::howManyNewCollectorsCome(int c)
{
			if (c == 20) return c;
			if (storedTreasure > 10)
			{
				c++;
				storedTreasure -= 10;
			}
		return c;
}
int Settlement::howManyNewSoldiersCome(int s)
{
			if (s == 20) return s;
			if (storedTreasure > 10)
			{
				s++;
				storedTreasure -= 10;
			}
		return s;
}
int Settlement::howManyNewBuildersCome(int b)
{
			if (b == 20) return b;
			if (storedTreasure > 10)
			{
				b++;
				storedTreasure -= 10;
			}
		return b;
}

void Settlement::checkCondition(int condition)
{
	if (condition <= 0)
	{
		isAlive = 0;
	}
}

