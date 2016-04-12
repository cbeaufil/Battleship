/*cse20212, board.cpp

*/

#include "Board.h"
#include "Ship.h"
#include <iostream>
#include <string>
<<<<<<< HEAD
=======

>>>>>>> 7612f112d56655db605b69e6131871668c599326
using namespace std;

Board::Board(int size) {
	boardSize = size;

	vector<char> row; // create one vector for each row

	for (int i=0; i < boardSize; i++) {
		row.push_back('O'); // input the value into the row vector
	}

	for (int i=0; i < boardSize; i++) {
		userBoard.push_back(row); // create the puzzle one row at a time
<<<<<<< HEAD
=======
		computerBoard.push_back(row);
>>>>>>> 7612f112d56655db605b69e6131871668c599326
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

<<<<<<< HEAD
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
=======
void Board::play() {
	char letterChoice;
	int game = 1;

	// placeships();

	while (game) {
		// Player Turn
		do {
			cout << "Choose a letter to select a spot to send in a missile: ";
			cin >> letterChoice;
			spotA = toupper(letterChoice) - 65;
			cout << "Choose a number to select a spot to send in a missile: ";
			cin >> spotB;
			spotB = spotB - 1;
			if (checkValid(spotA, spotB)) {
				break;
			}
		} while (1);

		previousPosition = computerBoard[spotA][spotB];
		if (computerBoard[spotA][spotB] != 'O') {
			computerBoard[spotA][spotB] = 'H';
			cout << "That's a hit!" << endl;
		}
		else {
			computerBoard[spotA][spotB] = 'M';
			cout << "You missed!" << endl;
		}

		// AI Turn
		// Reilly inputs computer turn here. Already instantiated a board for the user and the computer.
	// cout << computerBoard;
	}

}

int Board::checkValid(int spotA, int spotB) {
	
	if (spotA > 9 || spotA < 0) {
		cout << "You cannot shoot a missle here, try a new strategy!" << endl;
		return 0;
	}
	else if (spotB > 9 || spotB < 0) {
		cout << "You cannot shoot a missle here, try a new strategy!" << endl;
		return 0;
	}
	else if (computerBoard[spotA][spotB] == 'M') {
		cout << "You have already shot a missle here! Try a new strategy." << endl;
		return 0;
	}

	return 1;
}


>>>>>>> 7612f112d56655db605b69e6131871668c599326

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
