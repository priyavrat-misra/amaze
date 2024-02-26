# -*- MakeFile -*-

amaze: main.o Maze.o Game.o
	g++ main.o Maze.o Game.o -o amaze -lsfml-system -lsfml-window -lsfml-graphics

main.o: src/main.cpp include/Game.hpp
	g++ -c -O2 -I include/ src/main.cpp

Maze.o: src/Maze.cpp include/Maze.hpp
	g++ -c -O2 -I include/ src/Maze.cpp

Game.o: src/Game.cpp include/Maze.hpp include/Game.hpp
	g++ -c -O2 -I include/ src/Game.cpp

clean:
	rm *.o amaze
