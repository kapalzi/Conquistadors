#include "stdafx.h"
#include "Soldier.h"


Soldier::Soldier(int health, int hunger, int attack, int defence)
	:Human(health, hunger), attack(attack), defence(defence)
{
	soldiers.insert(soldiers.begin(), 40, new Soldier());
}


Soldier::~Soldier()
{
}
