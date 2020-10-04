#include "spaceship.h"

Spaceship::Spaceship(std::string name, bool real, int constructionDate, float length, float maximumVelocity, Fuel fuel)
{
	this->name = name;
	this->real = real;
	this->constructionDate = constructionDate;
	this->length = length;
	this->maximumVelocity = maximumVelocity;
	this->fuel = fuel;
}
