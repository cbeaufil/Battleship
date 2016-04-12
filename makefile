battleship: battleship.o Board.o Ship.o
	g++ battleship.o Board.o Ship.o -o battleship

battleship.o: battleship.cpp Board.h makefile

Board.o: Board.cpp Board.h makefile

Ship.o: Ship.cpp Ship.h makefile

clean:
	rm -f *.o battleship
