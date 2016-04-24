//Battleship
//Destroyer.cpp

#include "Destroyer.h"

Destroyer::Destroyer() : Ship("Destroyer", 1, 3, 0){
}

int Destroyer::getLength(){
	return length;
}