// Conquistadors.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "Settlement.h"
#include "Collector.h"

int main()
{
	Settlement newSettlement;
	Collector collectors;

	while (newSettlement.isAlive)
	{
		//new day starts
		collectors.collectorsGoOut();
		newSettlement.setStoredFood(collectors.collectorsComeBackWithFood());
		newSettlement.setStoredTreasure(collectors.collectorsComeBackWithTreasure());

	}






    return 0;
}

