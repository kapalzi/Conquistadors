#pragma once
#include "Human.h"
#include <vector>
using namespace std;
class Builder : public Human
{
	int tired;
	static int builderCounter;
public:
	Builder(int health = 100, int hunger = 100, int tired = 10);
	~Builder();

	 vector<Builder*>builders;

	int getTired() { return tired; }

	void setTired(int tired) { this->tired = tired; }
};

