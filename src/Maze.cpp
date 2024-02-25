#include <cstdlib>
#include <ctime>
#include <vector>

#include "Direction.h"
#include "Maze.h"

#define CELL_WIDTH 30
#define CELL_HEIGHT 30
#define PATH_THICKNESS 5

Maze::Maze(const int &window_width, const int &window_height)
    : width(window_width / (CELL_WIDTH + 2 * PATH_THICKNESS)),
      height(window_height / (CELL_HEIGHT + 2 * PATH_THICKNESS)),
      n_cells(width * height),
      grid(new unsigned char[n_cells]{0}),
      cell(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT)),
      horizontalPath(sf::Vector2f(PATH_THICKNESS, CELL_HEIGHT)),
      verticalPath(sf::Vector2f(CELL_WIDTH, PATH_THICKNESS)) {
    srand(clock());
    cell_stack.push(rand() % n_cells);
    n_visited = 1;
}

Maze::~Maze() { delete[] grid; }

void Maze::step(sf::RenderWindow &window) {
    if (n_visited < n_cells) {
        const int &t = cell_stack.top();
        std::vector<Direction> next_direction;

        if (t >= width && !grid[t - width]) next_direction.push_back(N);
        if (t % width < width - 1 && !grid[t + 1]) next_direction.push_back(E);
        if (t / width < height - 1 && !grid[t + width]) next_direction.push_back(S);
        if (t % width && !grid[t - 1]) next_direction.push_back(W);

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
