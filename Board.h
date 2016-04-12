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
<<<<<<< HEAD
	void userplaceship(Ship s, int, int);
	void computerplaceship(Ship s, int, int);

	private:
	int boardSize;
	vector< vector<char> > userBoard;
	vector< vector<char> > computerBoard;
=======
	void play();
	int checkValid(int, int);

	private:
	int boardSize;
	int spotA;
	int spotB;
	int previousPosition;
	vector< vector<char> > userBoard;
	vector< vector<char> > computerBoard;
	
>>>>>>> 7612f112d56655db605b69e6131871668c599326

};
#endif


