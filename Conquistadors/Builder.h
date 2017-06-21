#pragma once
#include "Human.h"
#include <vector>
using namespace std;
class Builder : public Human
{
	int tired;
public:
	Builder(int hunger = 100, int tired = 0);

	int getTired() { return tired; }

	void setTired(int tired) { this->tired += tired; }
	void resetTired() { this->tired = 0; }
};

