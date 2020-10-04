#include "StartGame.h"
using namespace std;

StartGame::StartGame() {
	cout << endl;
	cout << "Welcome to the Cosmonuts' game demo!" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Our planet is dying and only YOU can save it!!!\nScientists have been warning us for decades about climate change but it's too late now. Our only hope as humanity is to colonize another planet.\nWhat everyone expects you to do is to make the right decisions concerning the interstellar travel several of our top scientists are about to make. Are you ready to take your chances and save mankind?" << endl;
	cout << endl;
	cout << "The rules are simple, well, somewhat. In this demo, all you have to do is make decisions about the destination, the quantity of the fuel and the crew capacity. Sounds easy right? Well... It's not.\nThere are tons of things that can go wrong and most of them depend on the decisions you're making.\n We can't give you any more info, you'll have to see for yourself.\nRemember, you are humanity's final hope!" << endl;
	cout << endl;
}

StartGame::~StartGame(){
cout << "GAME OVER! If you won, congrats. If not, you can start over, it's just a game afterall!" << endl;
}
