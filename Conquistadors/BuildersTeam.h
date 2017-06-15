#pragma once
#include "Builder.h"
class BuildersTeam :
	public Builder
{
public:
	vector<Builder*>buildersPack;

	BuildersTeam();
	~BuildersTeam();
	
	int dailyHunger();
	void isBuilderDead();
	int rebuildSettlement(int condition);
	void builderDie(int d);
	int dailyEating(int needed, int stored);
};

