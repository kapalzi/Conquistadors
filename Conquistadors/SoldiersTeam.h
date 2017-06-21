#pragma once
#include "Soldier.h"
#include <iostream>
class SoldiersTeam :
	public Soldier
{
public:
	vector<Soldier*>soldiersPack;

	SoldiersTeam();

	int indiansAttack(int days);
	int battleResult(int x);
	

	int dailyHunger();
	void isSoldierDead();
	void soldierDie(int d);
	int dailyEating(int needed, int stored);
};

