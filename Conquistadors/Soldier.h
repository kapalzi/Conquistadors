#pragma once
#include "Human.h"
class Soldier : public Human
{
	int attack;
	int defence;
	static int soldierCounter;
public:
	Soldier(int health = 100, int hunger = 100, int attack = 10, int defense = 3 );
	~Soldier();

	static int getSoldierCounter() { return soldierCounter; }
	int getAttack() { return attack; }
	int getDefence() { return defence; }

	void setAttack(int attack) { this->attack = attack; }
	// s.setAttack(s.getAttack() + a)
	void setDefence(int defence) { this->attack = defence; }
	
};

