#include "stdafx.h"
#include "Human.h"

Human::Human(int health, int hunger):health(health), hunger(hunger)
{
	//counter++;
}


Human::~Human()
{
	//counter--;
}

int Human::random(int a, int b)
{
	srand(time(NULL));
	int r = (rand() % (b - a + 1) + a);
	return r;
}