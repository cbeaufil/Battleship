//Battleship
//Submarine.cpp

#include "Submarine.h"

Submarine::Submarine() : Ship("Submarine", 1){
	length = 5;
}

int Submarine::getLength(){
	return length;
}