#pragma once
class Human
{
	int health;
	int hunger;
	static int counter;
public:

	Human(int health, int hunger);
	~Human();
	static int getCounter() { return counter; }
	int getHealth() { return health; }
	int getHunger() { return hunger; }
	void setHealth(int health) { this->health = health; }
	void setHunger(int hunger) { this->health = hunger; }
};
