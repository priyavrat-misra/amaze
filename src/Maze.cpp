#include <cstdlib>
#include <ctime>
#include <vector>

#include "Maze.hpp"
#include "Game.hpp"

Maze::Maze(int width, int height, Game *const game)
    : width(width),
      height(height),
      grid(new unsigned char[width * height]{0}),
      game(game) {
    srand(clock());
    cell_stack.push(rand() % (width * height));
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
        game -> drawPath(t % width, t / width, next_direction);
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
    } else {
        game -> drawCell(t % width, t / width);
        cell_stack.pop();
    }
}
