#include "Destination.h"

#include <iostream>

Destination::Destination()
{
	this->distance = 0.0;
	this->name = "blank";
}

void Destination::setDestination(int destname)
{
	switch (destname) {
	case 1: name = "Proxima Centauri B"; distance = 4.22; break;
	case 2: name = "Gilese 667"; distance = 23.62; break;
	case 3: name = "Kepler-4426"; distance = 1291.6; break;
	case 4: name = "Kapteyn 6"; distance = 13.0; break;
	case 5: name = "TRAPPIST-1d"; distance = 39.0; break;
	case 6: name = "LHS 11456"; distance = 40.0; break;
	case 7: name = "Kepler-16386"; distance = 2491.83; break;
	case 8: name = "Teegarden-c"; distance = 12.58; break;
	case 9: name = "Kepler-186l"; distance = 561.0; break;
	case 10: name = "Luyten 6"; distance = 12.36; break;
	default: distance = 0;
	}
}

float Destination::getDistance() const
{
	return distance;
}
