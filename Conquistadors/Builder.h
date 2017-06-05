#pragma once
#include "Human.h"
class Builder : public Human
{
	int tired;
	static int builderCounter;
public:
	Builder(int health = 100, int hunger = 100, int tired = 10);
	~Builder();

	int getTired() { return tired; }

	void setTired(int tired) { this->tired = tired; }
};

