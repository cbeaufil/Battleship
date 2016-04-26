//David Durkin, Matt Reilly, Chris Beaufils
//Battleship program Ship.cpp

#include "Ship.h"

Ship::Ship(string nameIN, int verticalIN, int lengthIN, int hitsIN){
	vertical = verticalIN;
	name = nameIN;
	length = lengthIN;
	hits = hitsIN;
}

void Ship::setOrientation(int verticalIn){
	vertical = verticalIn;
}

int Ship::getLength() {
	return length;
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

int Ship::isSunk(){
	if(hits >= length){
		return 1;
	}
	else{
		return 0;
	}
}

void Ship::hit(){
	hits++;
}

void Ship::reset(){
	hits = 0;
}
