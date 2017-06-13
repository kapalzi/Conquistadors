#include "stdafx.h"
#include "Builder.h"

Builder::Builder(int health, int hunger, int tired)
	:Human(health, hunger), tired(tired)
{
}


Builder::~Builder()
{
}

