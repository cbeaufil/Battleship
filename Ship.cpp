//David Durkin, Matt Reilly, Chris Beaufils
//Battleship program Ship.cpp

#include "Ship.h"

Ship::Ship(){
	vertical = 0;
}

void Ship::setOrientation(int verticalIn){
	vertical = verticalIn;
}

int Ship::getVertical(){
	return vertical;
}