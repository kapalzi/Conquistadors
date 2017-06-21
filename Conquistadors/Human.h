#pragma once
#include <cstdlib>
#include <ctime>
class Human
{
	int hunger;
public:
	Human(int hunger);
	int getHunger() { return hunger; }
	void setHunger(int hunger) { this->hunger += hunger; }

	int random(int a, int b);

};

