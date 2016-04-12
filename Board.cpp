/*cse20212, board.cpp

*/

#include "Board.h"
#include "Ship.h"
#include <iostream>
#include <string>
using namespace std;

Board::Board(int size) {
	boardSize = size;

	vector<char> row; // create one vector for each row

	for (int i=0; i < boardSize; i++) {
		row.push_back('O'); // input the value into the row vector
	}

	for (int i=0; i < boardSize; i++) {
		userBoard.push_back(row); // create the puzzle one row at a time
	}		
}

ostream & operator<<(ostream & output, const Board& b) {
	for(int i=0; i < b.boardSize; i++) { // loop through each row
		output << "| ";
                for(int j=0; j < b.boardSize; j++) { // loop through each column
			output << b.userBoard[i][j] << " | "; // display each value from the puzzle and format the output
                        }
                output << endl;
                output << "-----------------------------------------" << endl; // display a line between each row for formatting
        }
	return output;
}

void Board::userplaceship(Ship s, int row, int col, int vertical){
	
	if(s.getName() == "Carrier"){
		if vertical{
			userBoard[row][col] = 'C';
			userBoard[row+1][col] = 'C';
			userBoard[row+2][col] = 'C';
			userBoard[row+3][col] = 'C';
			userBoard[row+4][col] = 'C';
		}
		else{
			userBoard[row][col] = 'C';
			userBoard[row][col+1] = 'C';
			userBoard[row][col+2] = 'C';
			userBoard[row][col+3] = 'C';
			userBoard[row][col+4] = 'C';
		}
	}
	else if(s.getName() == "Battleship"){
		if vertical{
			userBoard[row][col] = 'B';
			userBoard[row][col] = 'B';
			userBoard[row][col] = 'B';
			userBoard[row][col] = 'B';
		}

	}
	else if(s.getName() == "Submarine"){
		userBoard[row][col] = 'S';
	}
	else if(s.getName() == "Destrocoler"){
		userBoard[row][col] = 'D';
	}
	else if(s.getName() == "PatrolBoat"){
		userBoard[row][col] = 'P';
	}
	else{
		cout << "Improper board name" << endl;
	}
}

void Board::computerplaceship(Ship s, int row, int col, int vertical){
	if(s.getName() == "Carrier"){
		computerBoard[row][col] = 'C';
	}
	else if(s.getName() == "Battleship"){
		computerBoard[row][col] = 'B';
	}
	else if(s.getName() == "Submarine"){
		computerBoard[row][col] = 'S';
	}
	else if(s.getName() == "Destrocoler"){
		computerBoard[row][col] = 'D';
	}
	else if(s.getName() == "PatrolBoat"){
		computerBoard[row][col] = 'P';
	}
	else{
		cout << "Improper board name" << endl;
	}
}
