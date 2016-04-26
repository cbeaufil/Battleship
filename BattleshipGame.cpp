/* cse20212, BattleshipGame.cpp
 */

#include "BattleshipGame.h"
#include "Ship.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

BattleshipGame::BattleshipGame(int size) {
	boardSize = size;
	compOnTarget = 0;
	shipSunk = 1;
	count = 1;
	direction = 1;
	value = 1;

	vector<char> row; // create one vector for each row

	for (int i=0; i < boardSize; i++) {
		row.push_back('O'); // input the value into the row vector
	}

	for (int i=0; i < boardSize; i++) {
		userBoard.push_back(row); // create the puzzle one row at a time
		computerBoard.push_back(row);
	}		
}

ostream & operator<<(ostream & output, const BattleshipGame& b) {
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

void BattleshipGame::displayUser(){
	for(int i = 0; i < boardSize; i++){
		cout << " | ";
		for(int j = 0; j < boardSize; j++){
			cout << userBoard[i][j] << " | ";
		}
		cout << endl;
		cout << "-----------------------------------------" << endl;
	}
}

void BattleshipGame::displayComputer(){
	for(int i = 0; i < boardSize; i++){
		cout << " | ";
		for(int j = 0; j < boardSize; j++){
			cout << computerBoard[i][j] << " | ";
		}
		cout << endl;
		cout << "-----------------------------------------" << endl;
	}
}

char BattleshipGame::getUser(int row, int col) const{
	return userBoard[row][col];
}

vector< vector<char> > BattleshipGame::getComputer(){
	return computerBoard;
}

int BattleshipGame::turn(int mouseX, int mouseY) {
	char letterChoice;
	int hit = 0;
	int Valid = 0;

	/*if (!permission) {
		cout << "Choose another spot!" << endl;
		return 1;
	}*/

	// Player Turn
	//do {
		//do {
			spotB = mouseX/28;
			spotA = mouseY/28;


/*				cout << "Choose a letter to select a spot to send in a missile: ";
				cin >> letterChoice;
				spotA = toupper(letterChoice) - 65;
				cout << "Choose a number to select a spot to send in a missile: ";
				cin >> spotB;
				spotB = spotB - 1;
*/			Valid = checkValid(spotA, spotB);
			if (!Valid) {
				return 1;
			}
		//} while (!Valid);

		
		if (computerBoard[spotA][spotB] != 'O') {
			computerBoard[spotA][spotB] = 'H';
			cout << "That's a hit!" << endl;
			hit = 1;
		} else {
			computerBoard[spotA][spotB] = 'M';
			cout << "You missed!" << endl;
			hit = 0;
		}
	//} while (hit);

	cout << "COMPUTER:" << endl;
	displayComputer();
	cout << "USER:" << endl;
	displayUser();

	game();

	if (userValue == 0) {
		cout << "The computer player has won!" << endl;
	} else if (computerValue == 0) {
		cout << "Congrats! You won!" << endl;
	}		
	return hit;
}

int BattleshipGame::game() {
	userValue = 0;
	computerValue = 0;

	for (int i=0; i < boardSize; i++) {
		for (int j=0; j < boardSize; j++) {
			if (userBoard[i][j] == 'B' || userBoard[i][j] == 'P' || userBoard[i][j] == 'S' || userBoard[i][j] == 'D' || userBoard[i][j] == 'C') {
				userValue++;
			}
			if (computerBoard[i][j] == 'B' || computerBoard[i][j] == 'P' || computerBoard[i][j] == 'S' || computerBoard[i][j] == 'D' || computerBoard[i][j] == 'C') {
				computerValue++;
			}
		}
	}

	if (userValue == 0) {
		return userValue;
	} else if (computerValue == 0) {
		return computerValue;
	} else {
		return 1;
	}
}

int BattleshipGame::checkValid(int spotA, int spotB) {
	
	if (spotA > 9 || spotA < 0) {
		cout << "You cannot shoot a missle here, try a new strategy!" << endl;
		return 0;
	}
	else if (spotB > 9 || spotB < 0) {
		cout << "You cannot shoot a missle here, try a new strategy!" << endl;
		return 0;
	}
	else if (computerBoard[spotA][spotB] == 'M' || computerBoard[spotA][spotB] == 'H') {
		cout << "You have already shot a missle here! Try a new strategy." << spotA << spotB << endl;
		return 0;
	}

	return 1;
}

void BattleshipGame::placeUserShips(){
	cout << "Place Your Ships. Ships will be placed extending to the right of or downwards from your grid selection." << endl; 
	int play = 1;
	char letter;
	int number, row, col, vertical, success;

	displayUser();
	do {
		cout << "Where would you like to place your Carrier?" << endl;
		cout << "Letter: ";
		cin >> letter;
		row = toupper(letter) - 65;
		cout << "Number: ";
		cin >> number;
		col = number - 1;
		cout << "1 for Vertical, 0 for Horizontal: ";
		cin >> vertical;
		success = userplaceship(carrier, row, col, vertical);	
		displayUser();
	} while (!success);
	success = 0;
	do {
		cout << "Where would you like to place your Battleship?" << endl;
		cout << "Letter: ";
		cin >> letter;
		row = toupper(letter) - 65;
		cout << "Number: ";
		cin >> number;
		col = number - 1;
		cout << "1 for Vertical, 0 for Horizontal: ";
		cin >> vertical;
		success = userplaceship(battleship, row, col, vertical);
		displayUser();
	} while (!success);
	success = 0;
	do {
		cout << "Where would you like to place your Submarine?" << endl;
		cout << "Letter: ";
		cin >> letter;
		row = toupper(letter) - 65;
		cout << "Number: ";
		cin >> number;
		col = number - 1;
		cout << "1 for Vertical, 0 for Horizontal: ";
		cin >> vertical;
		success = userplaceship(submarine, row, col, vertical);
		displayUser();
	} while (!success);
	success = 0;
	do {
		cout << "Where would you like to place your Destroyer?" << endl;
		cout << "Letter: ";
		cin >> letter;
		row = toupper(letter) - 65;
		cout << "Number: ";
		cin >> number;
		col = number - 1;
		cout << "1 for Vertical, 0 for Horizontal: ";
		cin >> vertical;
		success = userplaceship(destroyer, row, col, vertical);
		displayUser();
	} while (!success);
	success = 0;
	do {
		cout << "Where would you like to place your Patrol Boat?" << endl;
		cout << "Letter: ";
		cin >> letter;
		row = toupper(letter) - 65;
		cout << "Number: ";
		cin >> number;
		col = number - 1;
		cout << "1 for Vertical, 0 for Horizontal: ";
		cin >> vertical;
		success = userplaceship(patrolboat, row, col, vertical);
		displayUser();
	} while (!success);
}

void BattleshipGame::placeComputerShips() {
	int vertical = rand() % 2;

	computerplaceship(carrier, randrow(), randcol(), vertical);
	computerplaceship(battleship, randrow(), randcol(), vertical - 1);
	computerplaceship(submarine, randrow(), randcol(), vertical);
	computerplaceship(destroyer, randrow(), randcol(), vertical - 1);
	computerplaceship(patrolboat, randrow(), randcol(), vertical);
}

int BattleshipGame::randrow() {
	return rand() % 10;
}

int BattleshipGame::randcol() {
	return rand() % 10;
}

void BattleshipGame::computerPlay() {
	int row = randrow(), col = randcol();
	int left, right, down, up;

	do {
		value = game();
		if (!value) {
			break;
		}
		if (!shipSunk) {
			compOnTarget = 1;
			if (direction % 5 == 1) {
				left = checkLeft();
				if (left == 0) {
					direction += 1;
				}
			} else if (direction % 5 == 2) {
				right = checkRight();
				if (right == 0) {
					direction += 1;
				}
			} else if (direction % 5 == 3) {
				down = checkDown();
				if (down == 0) {
					direction += 1;
				}
			} else if (direction % 5 == 4) {
				up = checkUp();
				if (up == 0) {
					direction += 1;
				}
			} else {
				direction += 1;
			}
			continue;
		} else {
			count = 1;
		}

		
		if (userBoard[row][col] == 'C') {
			cout << "Computer hit!" << endl;
			userBoard[row][col] = 'H';
			compOnTarget = 1;
			compPrevRow = row;
			compPrevCol = col;
			shipSunk = 0;
			carrier.hit();
		} else if (userBoard[row][col] == 'B') {
			cout << "Computer hit!" << endl;
			userBoard[row][col] = 'H';
			compOnTarget = 1;
			compPrevRow = row;
			compPrevCol = col;
			shipSunk = 0;
			battleship.hit();
		} else if (userBoard[row][col] == 'S') {
			cout << "Computer hit!" << endl;
			userBoard[row][col] = 'H';
			compOnTarget = 1;
			compPrevRow = row;
			compPrevCol = col;
			shipSunk = 0;
			submarine.hit();
		} else if (userBoard[row][col] == 'D') {
			cout << "Computer hit!" << endl;
			userBoard[row][col] = 'H';
			compOnTarget = 1;
			compPrevRow = row;
			compPrevCol = col;
			shipSunk = 0;
			destroyer.hit();
		} else if (userBoard[row][col] == 'P') {
			cout << "Computer hit!" << endl;
			userBoard[row][col] = 'H';
			compOnTarget = 1;
			compPrevRow = row;
			compPrevCol = col;
			shipSunk = 0;
			patrolboat.hit();
		} else if (userBoard[row][col] == 'O') {
			userBoard[row][col] = 'M';
			cout << "Computer miss!" << endl;
			compOnTarget = 0;
		} else if (userBoard[row][col] == 'H' || userBoard[row][col] == 'M') {
			row = randrow();
			col = randcol();
			compOnTarget = 1;
		}
	} while(compOnTarget);

}

int BattleshipGame::checkLeft() {
	if (compPrevCol - count <= 9 && !shipSunk) {
		if (userBoard[compPrevRow][compPrevCol - count] == 'O' && userBoard[compPrevRow][compPrevCol - count] != 'M') {
			compOnTarget = 0;
			userBoard[compPrevRow][compPrevCol - count] = 'M';
			count = 1;
			cout << "Computer miss!" << endl;
			return 0;
		} else if (userBoard[compPrevRow][compPrevCol - count] == 'C') {
			userBoard[compPrevRow][compPrevCol - count] = 'H';
		    	count += 1;
			carrier.hit();
			shipSunk = carrier.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow][compPrevCol - count] == 'B') {
			userBoard[compPrevRow][compPrevCol - count] = 'H';
		    	count += 1;
			battleship.hit();
			shipSunk = battleship.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow][compPrevCol - count] == 'S') {
			userBoard[compPrevRow][compPrevCol - count] = 'H';
		    	count += 1;
			submarine.hit();
			shipSunk = submarine.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow][compPrevCol - count] == 'D') {
			userBoard[compPrevRow][compPrevCol - count] = 'H';
		    	count += 1;
			destroyer.hit();
			shipSunk = destroyer.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow][compPrevCol - count] == 'P') {
			userBoard[compPrevRow][compPrevCol - count] = 'H';
		    	count += 1;
			patrolboat.hit();
			shipSunk = patrolboat.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		}
	}
	return 0;
}

int BattleshipGame::checkRight() {
	if (compPrevCol + count <= 9 && !shipSunk) {
		if (userBoard[compPrevRow][compPrevCol + count] == 'O' && userBoard[compPrevRow][compPrevCol + count] != 'M') {
			compOnTarget = 0;
			userBoard[compPrevRow][compPrevCol + count] = 'M';
			count = 1;
			cout << "Computer miss!" << endl;
			return 0;
		} else if (userBoard[compPrevRow][compPrevCol + count] == 'C') {
			userBoard[compPrevRow][compPrevCol + count] = 'H';
		    	count += 1;
			carrier.hit();
			shipSunk = carrier.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow][compPrevCol + count] == 'B') {
			userBoard[compPrevRow][compPrevCol + count] = 'H';
		    	count += 1;
			battleship.hit();
			shipSunk = battleship.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow][compPrevCol + count] == 'S') {
			userBoard[compPrevRow][compPrevCol + count] = 'H';
		    	count += 1;
			submarine.hit();
			shipSunk = submarine.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow][compPrevCol + count] == 'D') {
			userBoard[compPrevRow][compPrevCol + count] = 'H';
		    	count += 1;
			destroyer.hit();
			shipSunk = destroyer.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow][compPrevCol + count] == 'P') {
			userBoard[compPrevRow][compPrevCol + count] = 'H';
		    	count += 1;
			patrolboat.hit();
			shipSunk = patrolboat.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		}
	}
	return 0;
}

int BattleshipGame::checkUp() {
	if (compPrevRow - count <= 9 && !shipSunk) {
		if (userBoard[compPrevRow - count][compPrevCol] == 'O' && userBoard[compPrevRow - count][compPrevCol] != 'M') {
			compOnTarget = 0;
			userBoard[compPrevRow - count][compPrevCol] = 'M';
			count = 1;
			cout << "Computer miss!" << endl;
			return 0;
		} else if (userBoard[compPrevRow - count][compPrevCol] == 'C') {
			userBoard[compPrevRow - count][compPrevCol] = 'H';
		    	count += 1;
			carrier.hit();
			shipSunk = carrier.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow - count][compPrevCol] == 'B') {
			userBoard[compPrevRow + count][compPrevCol] = 'H';
		    	count += 1;
			battleship.hit();
			shipSunk = battleship.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow - count][compPrevCol] == 'S') {
			userBoard[compPrevRow - count][compPrevCol] = 'H';
		    	count += 1;
			submarine.hit();
			shipSunk = submarine.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow - count][compPrevCol] == 'D') {
			userBoard[compPrevRow - count][compPrevCol] = 'H';
		    	count += 1;
			destroyer.hit();
			shipSunk = destroyer.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow - count][compPrevCol] == 'P') {
			userBoard[compPrevRow - count][compPrevCol] = 'H';
		    	count += 1;
			patrolboat.hit();
			shipSunk = patrolboat.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		}
	}
	return 0;
}

int BattleshipGame::checkDown() {
	if (compPrevRow + count <= 9 && !shipSunk) {
		if (userBoard[compPrevRow + count][compPrevCol] == 'O' && userBoard[compPrevRow + count][compPrevCol] != 'M') {
			compOnTarget = 0;
			userBoard[compPrevRow + count][compPrevCol] = 'M';
			count = 1;
			cout << "Computer miss!" << endl;
			return 0;
		} else if (userBoard[compPrevRow + count][compPrevCol] == 'C') {
			userBoard[compPrevRow + count][compPrevCol] = 'H';
		    	count += 1;
			carrier.hit();
			shipSunk = carrier.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow + count][compPrevCol] == 'B') {
			userBoard[compPrevRow + count][compPrevCol] = 'H';
		    	count += 1;
			battleship.hit();
			shipSunk = battleship.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow + count][compPrevCol] == 'S') {
			userBoard[compPrevRow + count][compPrevCol] = 'H';
		    	count += 1;
			submarine.hit();
			shipSunk = submarine.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow + count][compPrevCol] == 'D') {
			userBoard[compPrevRow + count][compPrevCol] = 'H';
		    	count += 1;
			destroyer.hit();
			shipSunk = destroyer.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		} else if (userBoard[compPrevRow + count][compPrevCol] == 'P') {
			userBoard[compPrevRow + count][compPrevCol] = 'H';
		    	count += 1;
			patrolboat.hit();
			shipSunk = patrolboat.isSunk();
			cout << "Computer hit!" << endl;
			return 1;
		}   
	}
    return 0;
}

int BattleshipGame::placementValid (Ship s, int row, int col, int vertical) {
	int length = s.getLength();
	int alpha, digit;
	char a, d;

	//a = row;
	d = '0' + col;

	//alpha = isalpha(a);
	//cout << "the row is " << alpha << " and the column is " << digit << " row is " << col << endl;
	if (!isdigit(d)) {
		return 0;
	}

	if (vertical) {
		for (int i = 0; i < s.getLength(); i++) {
			if (row + length > 10 || col > 9 || row < 0 || col < 0 ||  userBoard[row + i][col] != 'O') {
				return 0;
			}
		}
	} else {
		for (int i = 0; i < s.getLength(); i++) {
			if (row > 9 || col + length > 10 || row < 0 || col < 0 ||  userBoard[row][col + i] != 'O') {
				return 0;
			}
		}
	}
	return 1;

}

int BattleshipGame::userplaceship (Ship s, int row, int col, int vertical){
	if(s.getName() == "Carrier"){
		if (placementValid(carrier, row, col, vertical)) {
			if (vertical){
					userBoard[row][col] = 'C';
					userBoard[row+1][col] = 'C';
					userBoard[row+2][col] = 'C';
					userBoard[row+3][col] = 'C';
					userBoard[row+4][col] = 'C';

			} else{
					userBoard[row][col] = 'C';
					userBoard[row][col+1] = 'C';
					userBoard[row][col+2] = 'C';
					userBoard[row][col+3] = 'C';
					userBoard[row][col+4] = 'C';
			}
			return 1;
		} else {
			cout << "You cannot place a ship here. Try Again!" << endl;
			return 0;
		}
	}
	else if(s.getName() == "Battleship"){
		if (placementValid(battleship, row, col, vertical)) {
			if (vertical){
					userBoard[row][col] = 'B';
					userBoard[row+1][col] = 'B';
					userBoard[row+2][col] = 'B';
					userBoard[row+3][col] = 'B';

			} else{
					userBoard[row][col] = 'B';
					userBoard[row][col+1] = 'B';
					userBoard[row][col+2] = 'B';
					userBoard[row][col+3] = 'B';
			}
			return 1;
		} else {
			cout << "You cannot place a ship here. Try Again!" << endl;
			return 0;
		}
	}
	else if(s.getName() == "Submarine"){
		if (placementValid(submarine, row, col, vertical)) {
			if (vertical){
					userBoard[row][col] = 'S';
					userBoard[row+1][col] = 'S';
					userBoard[row+2][col] = 'S';
			} else{
					userBoard[row][col] = 'S';
					userBoard[row][col+1] = 'S';
					userBoard[row][col+2] = 'S';

			}
			return 1;
		} else {
			cout << "You cannot place a ship here. Try Again!" << endl;
			return 0;
		}
	}
	else if(s.getName() == "Destroyer"){
		if (placementValid(destroyer, row, col, vertical)) {
			if (vertical){
				userBoard[row][col] = 'D';
				userBoard[row+1][col] = 'D';
				userBoard[row+2][col] = 'D';

			} else{
				userBoard[row][col] = 'D';
				userBoard[row][col+1] = 'D';
				userBoard[row][col+2] = 'D';
			}
			return 1;
		} else {
			cout << "You cannot place a ship here. Try Again!" << endl;
			return 0;
		}
	}
	else if(s.getName() == "PatrolBoat"){
		if (placementValid(patrolboat, row, col, vertical)) {
			if (vertical){
				userBoard[row][col] = 'P';
				userBoard[row+1][col] = 'P';
			} else{
				userBoard[row][col] = 'P';
				userBoard[row][col+1] = 'P';
			}
			return 1;
		} else {
			cout << "You cannot place a ship here. Try Again!" << endl;
			return 0;
		}
	}
	else{
		cout << "Improper ship name" << endl;
	}
}

void BattleshipGame::computerplaceship(Ship s, int row, int col, int vertical){
	int counter;

	if(s.getName() == "Carrier"){

		if (vertical){
			do {
				counter = 0;
				for (int i=0; i < 5; i++) {
					if (computerBoard[row + i][col] != 'O' || row + 4 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'C';
			computerBoard[row+1][col] = 'C';
			computerBoard[row+2][col] = 'C';
			computerBoard[row+3][col] = 'C';
			computerBoard[row+4][col] = 'C';
		}
		else{
			do {
				counter = 0;
				for (int i=0; i < 5; i++) {
					if (computerBoard[row][col + i] != 'O' || col + 4 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'C';
			computerBoard[row][col+1] = 'C';
			computerBoard[row][col+2] = 'C';
			computerBoard[row][col+3] = 'C';
			computerBoard[row][col+4] = 'C';
		}
	}
	else if(s.getName() == "Battleship"){
		if (vertical){
			do {
				counter = 0;
				for (int i=0; i < 4; i++) {
					if (computerBoard[row + i][col] != 'O' || row + 3 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'B';
			computerBoard[row+1][col] = 'B';
			computerBoard[row+2][col] = 'B';
			computerBoard[row+3][col] = 'B';
		}
		else{
			do {
				counter = 0;
				for (int i=0; i < 4; i++) {
					if (computerBoard[row][col + i] != 'O' || col + 3 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'B';
			computerBoard[row][col+1] = 'B';
			computerBoard[row][col+2] = 'B';
			computerBoard[row][col+3] = 'B';
		}
	}
	else if(s.getName() == "Submarine"){
		if (vertical){
			do {
				counter = 0;
				for (int i=0; i < 3; i++) {
					if (computerBoard[row + i][col] != 'O' || row + 2 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'S';
			computerBoard[row+1][col] = 'S';
			computerBoard[row+2][col] = 'S';
		}
		else{
			do {
				counter = 0;
				for (int i=0; i < 3; i++) {
					if (computerBoard[row][col + i] != 'O' || col + 2 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'S';
			computerBoard[row][col+1] = 'S';
			computerBoard[row][col+2] = 'S';
		}
	}
	else if(s.getName() == "Destroyer"){
		if (vertical){
			do {
				counter = 0;
				for (int i=0; i < 3; i++) {
					if (computerBoard[row + i][col] != 'O' || row + 2 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'D';
			computerBoard[row+1][col] = 'D';
			computerBoard[row+2][col] = 'D';
		}
		else{
			do {
				counter = 0;
				for (int i=0; i < 3; i++) {
					if (computerBoard[row][col + i] != 'O' || col + 2 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'D';
			computerBoard[row][col+1] = 'D';
			computerBoard[row][col+2] = 'D';
		}
	}
	else if(s.getName() == "PatrolBoat"){
		if (vertical){
			do {
				counter = 0;
				for (int i=0; i < 2; i++) {
					if (computerBoard[row + i][col] != 'O' || row + 1 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'P';
			computerBoard[row+1][col] = 'P';
		}
		else{
			do {
				counter = 0;
				for (int i=0; i < 2; i++) {
					if (computerBoard[row][col + i] != 'O' || col + 1 > 9) {
						row = randrow();
						col = randcol();
						counter++;
					}
				}
				if (counter == 0) {
					break;
				}
			} while (1);
			computerBoard[row][col] = 'P';
			computerBoard[row][col+1] = 'P';
		}
	}
	else{
		cout << "Improper ship name" << endl;
	}
}
