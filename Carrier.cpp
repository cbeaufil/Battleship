//Battleship
//Carrier.cpp

#include "Carrier.h"

Carrier::Carrier() : Ship("Carrier", 1){
	length = 5;
}

int Carrier::getLength(){
	return length;
}