#include <cstdlib>
#include <ctime>
#include <stack>
#include <vector>

#include "maze.h"

Maze::Maze(const int &width, const int &height)
    : grid(new unsigned char[width * height]{0}),
      width(width),
      height(height),
      n_cells(width * height) {
    srand(clock());
    generate(rand() % n_cells);
}

Maze::~Maze() { delete[] grid; }

void Maze::generate(const int &i) {
    std::stack<int> cell_stack;
    cell_stack.push(i);
    int n_visited = 1;

    while (n_visited < n_cells) {
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
