//David Durkin, Matt Reilly, Chris Beaufils
//Battleship program Ship.cpp

#include "Ship.h"

Ship::Ship(int verticalIN, string nameIN){
	vertical = verticalIN;
	name = nameIN;
}

void Ship::setOrientation(int verticalIn){
	vertical = verticalIn;
}

int Ship::getVertical(){
	return vertical;
}

void Ship::setName(string in){
	name = in;
}

string Ship::getName(){
	return name;
}