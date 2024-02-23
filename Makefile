# -*- MakeFile -*-

amaze: main.o maze.o
	g++ main.o maze.o -o amaze

main.o: src/main.cpp include/maze.h
	g++ -c -O2 -I include/ src/main.cpp

maze.o: src/maze.cpp include/maze.h
	g++ -c -O2 -I include/ src/maze.cpp

clean:
	rm *.o amaze
