#include <iostream>
#include <cstdlib>
#include <ctime>

#define EPSILON 0.001 //hehe

#include "spaceship.h"
#include "fusionRocket.h"
#include "Destination.h"

#include "StartGame.h"

using namespace std;

float timeFunc(Destination destination, float massOfFuel) {
	float tburn = massOfFuel / 0.05;
	float vmax = 540000 * 9.81 * log((1.2 * massOfFuel + 50000) / ((1.2 * massOfFuel + 50000) - 0.05 * tburn));
	float s1 = 540000 * 9.81 * ((tburn - (1.2 * massOfFuel + 50000) / 0.05) * log((1.2 * massOfFuel + 50000) / (1.2 * massOfFuel + 50000 - 0.05 * tburn)) + tburn);
	float s2 = (destination.getDistance()*9.46*pow(10, 15)) - s1;
	float t2 = s2 / vmax;
	cout << "Maximum velocity of your spacecraft was: " << vmax << "m/s" << endl;
	return ((t2 + tburn)*3.17*pow(10,-8));
}

FusionRocket chooseSpaceship(){
	cout << "You own a brand new Nuclear Fusion Rocket!" << endl;
	FusionRocket myRocket;
	int capacity = myRocket.chooseCrewCapacity();
	float mass = myRocket.chooseMassOfFuel();
	myRocket.setCrewCapacity(capacity);
	myRocket.setMassOfFuel(mass);
	return myRocket;
}

int chooseDestination() {
	unsigned int choice;
	cout << "Choose the destination of your travel by typing the number:" << endl;
	cout << "Have in mind that the furthest you reach, the highest is the possibility of habitability!" << endl;
	cout << "1. Proxima Centauri B (4.22 Light years away)" << endl;
	cout << "2. Gilese 667 (23.62 Light years away)" << endl;
	cout << "3. Kepler-4426 (1291.6 Light years away)" << endl;
	cout << "4. Kaitlyn 6 (13 Light years away)" << endl;
	cout << "5. TRAPPIST-1d (39 Light years away)" << endl;
	cout << "6. LHS 11456 (40 Light years away)" << endl;
	cout << "7. Kepler-16386 (2491.83 Light years away)" << endl;
	cout << "8. Teegarden-c (12.58 Light years away)" << endl;
	cout << "9. Kepler-186l (561 Light years away)" << endl;
	cout << "10. Luyten 6 (12,36 Light years away)" << endl;
	cin >> choice;
	return choice;
}

void status(int a) {
	cout << endl;
	cout << "You have " << a << " remaining crew members. Use them wisely!" << endl;
	cout << endl;
}

bool probabilityForNotAging(int massOfFuel)
{
	float probability;
	switch (massOfFuel)
	{
	case 1: probability = 0.15; break;
	case 2: probability = 0.75; break;
	case 3: probability = 0.95; break;
	case 4: probability = 0.85; break;
	case 5: probability = 0.15; break;
	default: probability = 1.00;
	}
	float flag = (float)(rand() % 100 + 1) / 100.0;
	if (flag <= probability) {
		return true;
	}
	return false;
}

bool probabilityForHabitability(int destination) {
	float probability;
	switch (destination)
	{
	case 1: probability = 0.30; break;
	case 2: probability = 0.20; break;
	case 3: probability = 0.90; break;
	case 4: probability = 0.70; break;
	case 5: probability = 0.35; break;
	case 6: probability = 0.45; break;
	case 7: probability = 0.95; break;
	case 8: probability = 0.15; break;
	case 9: probability = 0.85; break;
	case 10: probability = 0.25; break;
	default: probability = 1.00;
	}
	float flag = (float)(rand() % 100 + 1) / 100.0;
	if (flag <= probability) {
		return true;
	}
	return false;
}

bool probabilityForStayinAlive(int crewCapacity, bool& firstBoolean, bool& secondBoolean) {
	float probability;
	switch (crewCapacity)
	{
	case 1: probability = 0.20; break;
	case 2: probability = 0.50; break;
	case 3: probability = 0.90; break;
	case 4: probability = 0.95; break;
	case 5: probability = 0.75; break;
	case 6: probability = 0.65; break;
	case 7: probability = 0.45; break;
	case 8: probability = 0.35; break;
	case 9: probability = 0.25; break;
	case 10: probability = 0.15; break;
	default: probability = 1.00;
	}
	float flag = (float)(rand() % 100 + 1) / 100.0;
	if (flag <= probability) {
		firstBoolean = true;
	}
	flag = (float)(rand() % 100 + 1) / 100.0;
	if (flag <= 0.90) {
		secondBoolean = true;
	}
	if (firstBoolean == true && secondBoolean == true) {
		return true;
	}
	return false;
}

bool outcome(bool age, bool habitability, bool notdying, bool& firstBoolean, bool& secondBoolean) {
	if (age && habitability && notdying) {
		return true;
	}
	else if (age && !habitability && notdying) {
		cout << "You've managed to reach your destination, but the planet cannot sustain life." << endl;
		cout << "MISSION FAILED" << endl;
		return false;
	}
	else if (age && !habitability && !notdying) {
		cout << "Something terrible happened and your crew died along the way." << endl;
		if (firstBoolean) {
			cout << "There are two main theories on what happened. Either a meteor struck your ship or an unknown alien civilization intervened!" << endl;
		}
		else cout << "Your crew capacity choice was wrong. Choose better next time!" << endl;
		return false;
	}
	else if (age && habitability && !notdying) {
		cout << "Something terrible happened and your crew died along the way." << endl;
		if (firstBoolean) {
			cout << "There are two main theories on what happened. Either a meteor struck your ship or an unknown alien civilization intervened!" << endl;
		}
		else cout << "Your crew capacity choice was wrong. Choose better next time!" << endl;
		return false;
	}
	else if (!age && habitability && notdying) {
		cout << "The biosleep machines were at fault! You shouldn't have made that decision on the quantity of your fuel! Your crew died of old age" << endl;
		return false;
	}	
	else if (!age && !habitability && !notdying) {
		cout << "The biosleep machines were at fault! You shouldn't have made that decision on the quantity of your fuel! Your crew died of old age" << endl;
		return false;
	}
	else if (!age && !habitability && notdying) {
		cout << "The biosleep machines were at fault! You shouldn't have made that decision on the quantity of your fuel! Your crew died of old age" << endl;
		return false;
	}
	else if (!age && habitability && !notdying) {
		cout << "The biosleep machines were at fault! You shouldn't have made that decision on the quantity of your fuel! Your crew died of old age" << endl;
		return false;
	}

	return false;
}

int main() {
	srand(time(NULL));
	while (true) {
		StartGame start;
		int initcrew = 20000;
		while (initcrew > 0) {
			int destname = chooseDestination();
			Destination destination;
			destination.setDestination(destname);
			status(initcrew);
			FusionRocket ourRocket = chooseSpaceship();
			initcrew = initcrew - ourRocket.getCrewCapacity();
			float time = timeFunc(destination, ourRocket.getMassOfFuel());
			ourRocket.fusionRocketReset();
			cout << time << " Years Later..." << endl;
			cout << endl;
			bool age = probabilityForNotAging(ourRocket.getMassOfFuel());
			bool habitability = probabilityForHabitability(destname);
			bool firstBoolean = 0;
			bool secondBoolean = 0;
			bool notdying = probabilityForStayinAlive(ourRocket.getCrewCapacity(), firstBoolean, secondBoolean);
			bool win = outcome(age, habitability, notdying, firstBoolean, secondBoolean);
			if (win) {
				cout << "You did it, you saved the earth! Message was sent back to earth and colonization is begining!" << endl;
				break;
			}
			else cout << "Try again with your remaining crewmembers." << endl;
		}
		if (initcrew <= 0) cout << "All of your scientists were sent to suicide missions. You have noone left to send for expeditions. You failed..." << endl;
		cout << "END OF DEMO! Do you want to play again? Y/N: ";
		char c;
		cin >> c;
		if (c == 'N' || c == 'n') break;
	}
	return 0;
}