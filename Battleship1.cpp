//Battleship
//Battleship.cpp

#include "Battleship1.h"

Battleship1::Battleship1() : Ship("Battleship", 1){
	length = 5;
}

int Battleship1::getLength(){
	return length;
}