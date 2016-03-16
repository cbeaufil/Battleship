/* cse20212, Board.h

*/

#ifndef BOARD
#define BOARD

#include <iostream>
#include <vector>
using namespace std;

class Board {

	friend ostream& operator<<(ostream & output, const Board&);

	public:
	Board(int size=10);

	private:
	int boardSize;
	vector< vector<char> > display;

};
#endif


