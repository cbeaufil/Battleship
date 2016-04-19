/* cse20212, Board.h

*/

#ifndef BOARD
#define BOARD
#include "Ship.h"
#include <iostream>
#include <vector>
using namespace std;

class Board {

	friend ostream& operator<<(ostream & output, const Board&);

	public:
	Board(int size=10);
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

	private:
	int boardSize;
	int spotA;
	int spotB;
	int previousPosition;
    int compPrevRow;
    int compPrevCol;
    int compOnTarget = 0;   // Was last shot a hit?
    int compPrevHit;
	vector< vector<char> > userBoard;
	vector< vector<char> > computerBoard;

};

#endif