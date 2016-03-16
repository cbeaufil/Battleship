/*cse20212, board.cpp

*/

#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int size=10) {
	boardSize = size;

	vector<char> row; // create one vector for each row

	for (int i=0; i < boardSize; i++) {
		row.push_back(O); // input the value into the row vector
	}

	for (int i=0; i < boardSize; i++) {
		display.push_back(row); // create the puzzle one row at a time
	}		
}

ostream & operator<<(ostream & output, const Board&) {
	for(int i=0; i < boardSize; i++) { // loop through each row
		output << "| ";
                for(int j=0; j < boardSize; j++) { // loop through each column
			output << display[i][j] << " | "; // display each value from the puzzle and format the output
                        }
                output << endl;
                output << "-------------------------------------" << endl; // display a line between each row for formatting
        }
	return output;
}


