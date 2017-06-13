#pragma once
#include "Collector.h"
class collectorsTeam :
	public Collector
{

	

public:
	vector<Collector*>collectorsPack;

	collectorsTeam();
	~collectorsTeam();

	void collectorsGoOut();
	int collectorsComeBackWithFood();
	int collectorsComeBackWithTreasure();
	void collectorsWereAttacked();

	int dailyHunger();
	void isCollectorDead();
	void collectorsDie(int d);
	int dailyEating(int needed, int stored);
};

