#pragma once

class Maze {
private:
	int* grid;
	int width;
	int height;
public:
	Maze(const int& width, const int& height);
	~Maze();
};
