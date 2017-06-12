#include "stdafx.h"
#include "Builder.h"

Builder::Builder(int health, int hunger, int tired)
	:Human(health, hunger), tired(tired)
{
	builders.insert(builders.begin(), 20, new Builder());
}


Builder::~Builder()
{
}
