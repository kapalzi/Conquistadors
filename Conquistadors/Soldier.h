#pragma once
#include "Human.h"
#include <vector>
using namespace std;
class Soldier : public Human
{
	int combatPoints;
public:
	Soldier(int health = 100, int hunger = 100, int combatPoints = 10);
	~Soldier();
	int getcombatPoints() { return combatPoints; }

	void setCombatPoints(int combatPoints) { this->combatPoints += combatPoints; }
	int combatPointsMeaning(int combatPoints);
};

