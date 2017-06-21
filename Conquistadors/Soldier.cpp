#include "stdafx.h"
#include "Soldier.h"


Soldier::Soldier(int health, int hunger, int combatPoints)
	:Human( hunger), combatPoints(combatPoints)
{
}

int::Soldier::combatPointsMeaning(int combatPoints)
{
	int kills = 1;
	int i = 0;
	while (combatPoints<i)
	{
		i += 10;
	}
	return kills + i / 10;
}