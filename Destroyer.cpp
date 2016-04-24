//Battleship
//Destroyer.cpp

#include "Destroyer.h"

Destroyer::Destroyer() : Ship("Destroyer", 1){
	length = 5;
}

int Destroyer::getLength(){
	return length;
}