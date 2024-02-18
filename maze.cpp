#include "maze.h"
#include <ctime>
#include <algorithm>

Maze::Maze(const int &width, const int &height)
    : width(width), height(height), grid(new unsigned char[width * height]{0}) {
    srand(clock());
    generate(rand() % width, rand() % height);
}

Maze::~Maze() { delete[] grid; }

void Maze::generate(const int &x, const int &y) {
    Direction directions[4] = {N, E, S, W};
    std::random_shuffle(directions, directions + 4);
    for (Direction &direction : directions) {
        int dx = (((0xC0 & direction) << 24) >> 30);
        int dy = (((0x30 & direction) << 26) >> 30);
        if (isValidIndex(x + dx, y + dy) && !grid[offset(x + dx, y + dy)]) {
            grid[offset(x, y)] |= 0x0F & direction;
            generate(x + dx, y + dy);
        }
    }
}
