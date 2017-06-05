#include "stdafx.h"
#include "Human.h"


Human::Human(int health, int hunger):health(health), hunger(hunger)
{
	counter++;
}


Human::~Human()
{
	counter--;
}
