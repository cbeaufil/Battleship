//David Durkin, Matt Reilly, Chris Beaufils
//Battleship Program ship class 

#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;

class Ship {

public:
	Ship(int verticalIN, string nameIN);
	void setOrientation(int);
	int getVertical();
	string getName();
	void setName(string);

private:
	int vertical;
	string name;
	
};


#endif 