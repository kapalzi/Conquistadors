#include "stdafx.h"
#include "Collector.h"
#include <iostream>

Collector::Collector(int health, int hunger, int backpackCapacity)
	:Human(health, hunger), backpackCapacity(backpackCapacity)
{
}


Collector::~Collector()
{
}

void Collector::foodFound()
{
	if (backpackCapacity + 5 < 0) return;
	this->setFoundFood(this->getFoundFood() + 5);
	this->setBackpackCapacity(getBackpackCapacity() - 5);
}

void Collector::treasureFound()
{
	if (backpackCapacity + 1 < 0) return;
	this->setFoundTreasure(this->getFoundTreasure() + 1);
	this->setBackpackCapacity(getBackpackCapacity() - 1);
}
