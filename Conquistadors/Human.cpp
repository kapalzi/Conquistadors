#include "stdafx.h"
#include "Human.h"

Human::Human(int hunger): hunger(hunger)
{
}

int Human::random(int a, int b)
{
	int r = (rand() % (b - a + 1) + a);
	return r;
}