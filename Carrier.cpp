//Battleship
//Carrier.cpp

#include "Carrier.h"

Carrier::Carrier() : Ship("Carrier", 1, 5, 0){
}

int Carrier::getLength(){
	return length;
}