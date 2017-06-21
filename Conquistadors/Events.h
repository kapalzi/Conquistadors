#pragma once
#include "stdafx.h"
#include "Settlement.h"
#include <vector>
#include <iostream>
#include <ctime>
#include "collectorsTeam.h"
#include "BuildersTeam.h"
#include "SoldiersTeam.h"
#include <conio.h>
using namespace std;

class Events
{
public:
	Events();
	void addCollectors(int l);
	void addBuilders(int l);
	void addSoldiers(int l);
	void startSimulation();
};


