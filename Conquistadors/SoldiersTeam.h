#pragma once
#include "Soldier.h"
class SoldiersTeam :
	public Soldier
{
public:
	vector<Soldier*>soldiersPack;

	SoldiersTeam();
	~SoldiersTeam();

	int dailyHunger();
	void isSoldierDead();
	void soldierDie(int d);
	int dailyEating(int needed, int stored);
};

