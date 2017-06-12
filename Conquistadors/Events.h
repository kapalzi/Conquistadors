#pragma once
#include <cstdlib>
#include <ctime>
#include "Settlement.h"

class Events
{
	int dayCounter;
public:
	Events(int dayCounter = 1);
	~Events();
	void newDayStarts();
	void newDayEnds();
	 //random number a-b
	//virtual void collectorsGoOut() = 0;
};


