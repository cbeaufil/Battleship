//Battleship
//PatrolBoat.cpp

#include "PatrolBoat.h"

PatrolBoat::PatrolBoat() : Ship("PatrolBoat", 1){
	length = 5;
}

int PatrolBoat::getLength(){
	return length;
}