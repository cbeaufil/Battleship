battleship: battleship.o Board.o
	g++ battleship.o -o battleship

battleship.o: battleship.cpp Board.h
	g++ -c battleship.cpp
Board.o: Board.cpp Board.h
	g++ -o Board.cpp

clean:
	rm -f *.o battleship
