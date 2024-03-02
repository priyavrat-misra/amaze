#include <cstdlib>
#include <ctime>
#include <vector>

#include "Direction.hpp"
#include "Maze.hpp"

Maze::Maze(int width, int height, Renderer &renderer)
    : width(width),
      height(height),
      n_cells(width * height),
      grid(new unsigned char[n_cells]{0}),
      renderer(renderer) {
    srand(clock());
    cell_stack.push(rand() % n_cells);
    n_visited = 1;
}

Maze::~Maze() { delete[] grid; }

void Maze::step() {
    const int &t = cell_stack.top();
    std::vector<Direction> next_directions;

    if (t >= width && !grid[t - width]) next_directions.push_back(N);
    if (t % width < width - 1 && !grid[t + 1]) next_directions.push_back(E);
    if (t / width < height - 1 && !grid[t + width]) next_directions.push_back(S);
    if (t % width && !grid[t - 1]) next_directions.push_back(W);

    if (!next_directions.empty()) {
        Direction &next_direction = next_directions[rand() % next_directions.size()];
        grid[t] |= next_direction;
        renderer.drawPath(t % width, t / width, next_direction);
        switch (next_direction) {
            case N:
                grid[t - width] |= S;
                cell_stack.push(t - width);
                break;
            case E:
                grid[t + 1] |= W;
                cell_stack.push(t + 1);
                break;
            case S:
                grid[t + width] |= N;
                cell_stack.push(t + width);
                break;
            case W:
                grid[t - 1] |= E;
                cell_stack.push(t - 1);
                break;
        }
        ++n_visited;
    } else {
        renderer.drawCell(t % width, t / width);
        cell_stack.pop();
    }
}
