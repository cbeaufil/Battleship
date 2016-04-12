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
		computerBoard.push_back(row);
	}		
}

ostream & operator<<(ostream & output, const Board& b) {
	for(int i=0; i < b.boardSize; i++) { // loop through each row
		output << "| ";
        for(int j=0; j < b.boardSize; j++) { // loop through each column
			output << b.getUser(i, j) << " | "; // display each value from the puzzle and format the output
		}
        output << endl;
        output << "-----------------------------------------" << endl; // display a line between each row for formatting
    }
	return output;
}

void Board::displayUser(){
	for(int i = 0; i < boardSize; i++){
		cout << " | ";
		for(int j = 0; j < boardSize; j++){
			cout << userBoard[i][j] << " | ";
		}
		cout << endl;
		cout << "-----------------------------------------" << endl;
	}
}

void Board::displayComputer(){
	for(int i = 0; i < boardSize; i++){
		cout << " | ";
		for(int j = 0; j < boardSize; j++){
			cout << computerBoard[i][j] << " | ";
		}
		cout << endl;
		cout << "-----------------------------------------" << endl;
	}
}

char Board::getUser(int row, int col) const{
	return userBoard[row][col];
}

char Board::getComputer(int row, int col){
	return computerBoard[row][col];
}

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
	 	displayComputer();
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

void Board::placeUserShips(){
	cout << "Place Your Ships. Ships will be placed extending to the right of or downwards from your grid selection." << endl; 
	int play = 1;
	char letter;
	int number, row, col, vertical;
	Ship Carrier(1, "Carrier");
	Ship Battleship(1, "Battleship");
	Ship Submarine(1, "Submarine");
	Ship Destroyer(1, "Destroyer");
	Ship PatrolBoat(1, "PatrolBoat");

	while(play){
		displayUser();
		cout << "Where would you like to place your Carrier?" << endl;
		cout << "Letter: ";
		cin >> letter;
		row = toupper(letter) - 65;
		cout << "Number: ";
		cin >> number;
		col = number - 1;
		cout << "1 for Vertical, 0 for Horizontal";
		cin >> vertical;
		userplaceship(Carrier, row, col, vertical);
		
	}


}

void Board::userplaceship(Ship s, int row, int col, int vertical){
	if(s.getName() == "Carrier"){
		if (vertical){
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
		if (vertical){
			userBoard[row][col] = 'B';
			userBoard[row+1][col] = 'B';
			userBoard[row+2][col] = 'B';
			userBoard[row+3][col] = 'B';
		}
		else{
			userBoard[row][col] = 'B';
			userBoard[row][col+1] = 'B';
			userBoard[row][col+2] = 'B';
			userBoard[row][col+3] = 'B';
		}
	}
	else if(s.getName() == "Submarine"){
		if (vertical){
			userBoard[row][col] = 'S';
			userBoard[row+1][col] = 'S';
			userBoard[row+2][col] = 'S';
		}
		else{
			userBoard[row][col] = 'S';
			userBoard[row][col+1] = 'S';
			userBoard[row][col+2] = 'S';
		}
	}
	else if(s.getName() == "Destroyer"){
		if (vertical){
			userBoard[row][col] = 'D';
			userBoard[row+1][col] = 'D';
			userBoard[row+2][col] = 'D';
		}
		else{
			userBoard[row][col] = 'D';
			userBoard[row][col+1] = 'D';
			userBoard[row][col+2] = 'D';
		}
	}
	else if(s.getName() == "PatrolBoat"){
		if (vertical){
			userBoard[row][col] = 'P';
			userBoard[row+1][col] = 'P';
		}
		else{
			userBoard[row][col] = 'P';
			userBoard[row][col+1] = 'P';
		}
	}
	else{
		cout << "Improper board name" << endl;
	}
}

void Board::computerplaceship(Ship s, int row, int col, int vertical){
	if(s.getName() == "Carrier"){
		if (vertical){
			computerBoard[row][col] = 'C';
			computerBoard[row+1][col] = 'C';
			computerBoard[row+2][col] = 'C';
			computerBoard[row+3][col] = 'C';
			computerBoard[row+4][col] = 'C';
		}
		else{
			computerBoard[row][col] = 'C';
			computerBoard[row][col+1] = 'C';
			computerBoard[row][col+2] = 'C';
			computerBoard[row][col+3] = 'C';
			computerBoard[row][col+4] = 'C';
		}
	}
	else if(s.getName() == "Battleship"){
		if (vertical){
			computerBoard[row][col] = 'B';
			computerBoard[row+1][col] = 'B';
			computerBoard[row+2][col] = 'B';
			computerBoard[row+3][col] = 'B';
		}
		else{
			computerBoard[row][col] = 'B';
			computerBoard[row][col+1] = 'B';
			computerBoard[row][col+2] = 'B';
			computerBoard[row][col+3] = 'B';
		}
	}
	else if(s.getName() == "Submarine"){
		if (vertical){
			computerBoard[row][col] = 'S';
			computerBoard[row+1][col] = 'S';
			computerBoard[row+2][col] = 'S';
		}
		else{
			computerBoard[row][col] = 'S';
			computerBoard[row][col+1] = 'S';
			computerBoard[row][col+2] = 'S';
		}
	}
	else if(s.getName() == "Destroyer"){
		if (vertical){
			computerBoard[row][col] = 'D';
			computerBoard[row+1][col] = 'D';
			computerBoard[row+2][col] = 'D';
		}
		else{
			computerBoard[row][col] = 'D';
			computerBoard[row][col+1] = 'D';
			computerBoard[row][col+2] = 'D';
		}
	}
	else if(s.getName() == "PatrolBoat"){
		if (vertical){
			computerBoard[row][col] = 'P';
			computerBoard[row+1][col] = 'P';
		}
		else{
			computerBoard[row][col] = 'P';
			computerBoard[row][col+1] = 'P';
		}
	}
	else{
		cout << "Improper board name" << endl;
	}
}
