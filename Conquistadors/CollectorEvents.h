#pragma once
#include "Collector.h"
#include "Settlement.h"
#include <vector>

class CollectorEvents :
	public Collector, public Settlement
{
public:
	CollectorEvents();
	~CollectorEvents();

//	static void collectorsGoOut();
};

