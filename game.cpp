/* cse20212, game.cpp


*/

#include "BattleshipGame.h"

using namespace std;

int main() {
	srand(time(NULL));

	BattleshipGame b;
	b.placeUserShips();
	b.placeComputerShips();
	b.play();
}
