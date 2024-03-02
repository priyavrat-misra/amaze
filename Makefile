# -*- MakeFile -*-

amaze: main.o Maze.o Renderer.o Game.o
	g++ main.o Maze.o Renderer.o Game.o -o amaze -lsfml-system -lsfml-window -lsfml-graphics

main.o: src/main.cpp include/Game.hpp
	g++ -c -O2 -I include/ src/main.cpp

Maze.o: src/Maze.cpp include/Maze.hpp include/Renderer.hpp include/Direction.hpp
	g++ -c -O2 -I include/ src/Maze.cpp

Renderer.o: src/Renderer.cpp include/Renderer.hpp include/Direction.hpp
	g++ -c -O2 -I include/ src/Renderer.cpp

Game.o: src/Game.cpp include/Game.hpp include/Maze.hpp include/Renderer.hpp
	g++ -c -O2 -I include/ src/Game.cpp

clean:
	rm *.o amaze
