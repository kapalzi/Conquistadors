#pragma once
#include "Collector.h"
class collectorsTeam :
	public Collector
{

	

public:
	vector<Collector*>collectorsPack;

	collectorsTeam();

	void collectorsGoOut();
	int collectorsComeBackWithFood();
	int collectorsComeBackWithTreasure();
	void collectorsWereAttacked();

	int dailyHunger();
	int dailyEating(int needed, int stored);
	void isCollectorDead();
	void collectorsDie(int d);
	
};

