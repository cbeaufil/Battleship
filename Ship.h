//David Durkin, Matt Reilly, Chris Beaufils
//Battleship Program ship class 

#ifndef SHIP_H
#define SHIP_H

class Ship {

public:
	Ship();
	void setOrientation(int);
	int getVertical();

private:
	int vertical;
	
};


#endif 