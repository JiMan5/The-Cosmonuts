#pragma once

#include <string>

class Destination
{
private:
	std::string name;
	float distance;

public:
	Destination();
	~Destination() {};

	void setDestination(int destname);

	float getDistance() const;
};