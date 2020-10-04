#pragma once

#include "spaceship.h"

class FusionRocket : public Spaceship
{
private:
	int crewCapacity;
	float massOfFuel;
public:
	FusionRocket();
	int chooseCrewCapacity();
	float chooseMassOfFuel();
	void setCrewCapacity(int crewCapacity) { this->crewCapacity = crewCapacity; }
	void setMassOfFuel(float massOfFuel) { this->massOfFuel = massOfFuel; }
	int getCrewCapacity() { return crewCapacity; }
	void fusionRocketReset();

	float getMassOfFuel() const;
};
