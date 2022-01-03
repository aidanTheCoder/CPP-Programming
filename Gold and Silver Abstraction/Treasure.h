#pragma once
#include "Volume.h"
#include "Weight.h"

class Treasure {
	Weight weight;
	Volume volume;
public:
	void setVolume(double newVolume);
	void setWeight(double newWeight);
	bool isPure(double density, double tolerance);
	static constexpr double GOLD = 19.3;
	static constexpr double SILVER = 10.5;
	static constexpr double ONE_PERCENT = .01;
	static constexpr double TENTH_PERCENT = .001;
};

