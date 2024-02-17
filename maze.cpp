#include "maze.h"

Maze::Maze(const int& width, const int& height): width(width), height(height) {
	grid = new int[width * height]{0};
}

Maze::~Maze() {
	delete[] grid;
}
