/* cse20212, BattleshipGame.h

*/

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include "Ship.h"
#include "Carrier.h"
#include "Battleship1.h"
#include "Destroyer.h"
#include "Submarine.h"
#include "PatrolBoat.h"
#include <iostream>
#include <vector>
using namespace std;

class BattleshipGame {

	friend ostream& operator<<(ostream & output, const BattleshipGame&);

	public:
	BattleshipGame(int size=10);
	void userplaceship(Ship s, int, int, int);
	void computerplaceship(Ship s, int, int, int);
	void play();
	int checkValid(int, int);
	char getUser(int, int) const;
	char getComputer(int, int);
	void displayUser();
	void displayComputer();
	void placeUserShips();
    int randrow();
    int randcol();
    void placeComputerShips();
	void computerPlay();
	int checkForAdjacentHits();

	private:
	int boardSize;
	int spotA;
	int spotB;
	int previousPosition;
    int compPrevRow;
    int compPrevCol;
    int compOnTarget;   // Was last shot a hit?
    int compPrevHit;
	vector< vector<char> > userBoard;
	vector< vector<char> > computerBoard;
	Carrier carrier;
	Battleship1 battleship;
	Destroyer destroyer;
	Submarine submarine;
	PatrolBoat patrolboat;

};

#endif
