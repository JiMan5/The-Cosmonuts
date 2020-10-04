#include "fusionRocket.h"
#include "spaceship.h"

#include <iostream>

FusionRocket::FusionRocket() : Spaceship("FuzyBoi", true, 0, 200, 0, LIQUIDHYDROGEN)
{
	this->crewCapacity = 0;
	this->massOfFuel = 0;
}

int FusionRocket::chooseCrewCapacity()
{
	std::cout << "Choose your spaceship's crew capacity:\n1. 1000\n2. 2000\n3. 3000\n4. 4000\n5. 5000\n6. 6000\n7. 7000\n8. 8000\n9. 9000\n10. 10000\n" << std::endl;
	std::cout << "Enter a number from 1 to 10.\n" << std::endl;
	int num;
	std::cin >> num;
	switch (num)
	{
	case 1: return 1000; break;
	case 2: return 2000; break;
	case 3: return 3000; break;
	case 4: return 4000; break;
	case 5: return 5000; break;
	case 6: return 6000; break;
	case 7: return 7000; break;
	case 8: return 8000; break;
	case 9: return 9000; break;
	case 10: return 10000; break;
	default: return 0;
	}
}

float FusionRocket::chooseMassOfFuel()
{
	std::cout << "Choose your spaceship's mass of fuel:\n1. 1000\n2. 10000\n3. 100000\n4. 1000000\n5. 10000000\n" << std::endl;
	std::cout << "Enter a number from 1 to 10.\n" << std::endl;
	int num;
	std::cin >> num;
	switch (num)
	{
	case 1: return 100000; break;
	case 2: return 1000000; break;
	case 3: return 10000000; break;
	case 4: return 100000000; break;
	case 5: return 1000000000; break;
	default: return 0;
	}
}

void FusionRocket::fusionRocketReset() {
	this->crewCapacity = 0;
	this->massOfFuel = 0;
}

float FusionRocket::getMassOfFuel() const
{
	return massOfFuel;
}
