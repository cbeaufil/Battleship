//Battleship
//Submarine.cpp

#include "Submarine.h"

Submarine::Submarine() : Ship("Submarine", 1, 3, 0){
}

int Submarine::getLength(){
	return length;
}