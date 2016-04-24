//David Durkin, Matt Reilly, Chris Beaufils
//Battleship Program ship class 

#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;

class Ship {

public:
	Ship(string nameIN, int verticalIN, int lengthIN, int hitsIN);
	void setOrientation(int);
	int getVertical();
	string getName();
	void setName(string);
	int isSunk();
	void hit();

private:
	int vertical;
	string name;
	int length;
	int hits;
	
};


#endif 