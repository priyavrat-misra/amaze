# -*- MakeFile -*-

amaze: main.o Maze.o
	g++ main.o Maze.o -o amaze

main.o: src/main.cpp include/Maze.h
	g++ -c -O2 -I include/ src/main.cpp

Maze.o: src/Maze.cpp include/Maze.h include/Direction.h
	g++ -c -O2 -I include/ src/Maze.cpp

clean:
	rm *.o amaze
