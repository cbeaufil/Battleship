//Battleship
//PatrolBoat.cpp

#include "PatrolBoat.h"

PatrolBoat::PatrolBoat() : Ship("PatrolBoat", 1, 2, 0){
}

int PatrolBoat::getLength(){
	return length;
}