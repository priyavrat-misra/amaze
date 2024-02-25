# -*- MakeFile -*-

amaze: main.o Maze.o Game.o
	g++ main.o Maze.o Game.o -o amaze -lsfml-system -lsfml-window -lsfml-graphics

main.o: src/main.cpp include/Game.h
	g++ -c -O2 -I include/ src/main.cpp

Maze.o: src/Maze.cpp include/Maze.h include/Direction.h
	g++ -c -O2 -I include/ src/Maze.cpp

Game.o: src/Game.cpp include/Maze.h include/Direction.h
	g++ -c -O2 -I include/ src/Game.cpp

clean:
	rm *.o amaze
