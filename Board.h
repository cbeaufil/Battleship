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
	void userplaceship(Ship s, int, int);
	void computerplaceship(Ship s, int, int);

	private:
	int boardSize;
	vector< vector<char> > userBoard;
	vector< vector<char> > computerBoard;

};
#endif


