#pragma once

#include <string>

enum Fuel{LIQUIDHYDROGEN, LIQUIDOXYGEN, HELIUM3, URANIUM};

class Spaceship
{
private:
	std::string name;
	bool real;
	int constructionDate;
	float length;
	float maximumVelocity;
	Fuel fuel;

public:
	Spaceship(std::string name, bool real, int constructionDate, float length, float maximumVelocity, Fuel fuel);
	~Spaceship() {};
	
	virtual int chooseCrewCapacity() = 0;
	virtual float chooseMassOfFuel() = 0;
};
