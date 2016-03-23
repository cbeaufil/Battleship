battleship: battleship.o Board.o
	g++ battleship.o Board.o -o battleship

battleship.o: battleship.cpp Board.h makefile

Board.o: Board.cpp Board.h makefile

clean:
	rm -f *.o battleship
