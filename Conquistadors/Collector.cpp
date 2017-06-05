#include "stdafx.h"
#include "Collector.h"


Collector::Collector(int health, int hunger, int backpackCapacity)
	:Human(health, hunger), backpackCapacity(backpackCapacity)
{
}


Collector::~Collector()
{
}
