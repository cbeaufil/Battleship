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
	void play();
	int checkValid(int, int);

	private:
	int boardSize;
	int spotA;
	int spotB;
	int previousPosition;
	vector< vector<char> > userBoard;
	vector< vector<char> > computerBoard;
	

};
#endif


