#include <cstdlib>
#include <ctime>
#include <vector>

#include "Direction.h"
#include "Maze.h"

Maze::Maze(const int &width, const int &height)
    : grid(new unsigned char[width * height]{0}),
      width(width),
      height(height),
      n_cells(width * height) {
    srand(clock());
    cell_stack.push(rand() % n_cells);
    n_visited = 1;
}

Maze::~Maze() { delete[] grid; }

void Maze::generate() {
    if (n_visited < n_cells) {
        const int &t = cell_stack.top();
        std::vector<Direction> next_direction;

        if (t >= width && !grid[t - width])
            next_direction.push_back(N);
        if (t % width < width - 1 && !grid[t + 1])
            next_direction.push_back(E);
        if (t / width < height - 1 && !grid[t + width])
            next_direction.push_back(S);
        if (t % width && !grid[t - 1])
            next_direction.push_back(W);

        if (!next_direction.empty()) {
            switch (next_direction[rand() % next_direction.size()]) {
                case N:
                    grid[t] |= N;
                    grid[t - width] |= S;
                    cell_stack.push(t - width);
                    break;
                case E:
                    grid[t] |= E;
                    grid[t + 1] |= W;
                    cell_stack.push(t + 1);
                    break;
                case S:
                    grid[t] |= S;
                    grid[t + width] |= N;
                    cell_stack.push(t + width);
                    break;
                case W:
                    grid[t] |= W;
                    grid[t - 1] |= E;
                    cell_stack.push(t - 1);
                    break;
            }
            ++n_visited;
        } else {
            cell_stack.pop();
        }
    }
}
