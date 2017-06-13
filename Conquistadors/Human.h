#pragma once
#include <cstdlib>
#include <ctime>
class Human
{
	int health;
	int hunger;
//	static int counter;
public:
	Human(int health , int hunger);
	~Human();
//	static int getCounter() { return counter; }
	int getHealth() { return health; }
	int getHunger() { return hunger; }
	void setHealth(int health) { this->health = health; }
	void setHunger(int hunger) { this->hunger += hunger; }

	int random(int a, int b);
	/*
	virtual int dailyHunger() = 0;
	virtual void isCollectorDead() = 0;
	virtual void collectorsDie(int d) = 0;
	virtual int dailyEating(int needed, int stored) = 0;
	*/
};

