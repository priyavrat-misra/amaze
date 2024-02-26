#include <cstdlib>
#include <ctime>
#include <vector>

#include "Maze.hpp"

#define XY(DX, DY)                                       \
    (t % width) * GRID_CELL_WIDTH + PATH_THICKNESS + DX, \
        (t / width) * GRID_CELL_HEIGHT + PATH_THICKNESS + DY
#define GRID_CELL_WIDTH (CELL_WIDTH + 2 * PATH_THICKNESS)
#define GRID_CELL_HEIGHT (CELL_HEIGHT + 2 * PATH_THICKNESS)

#define CELL_WIDTH 30
#define CELL_HEIGHT 30
#define PATH_THICKNESS 5

Maze::Maze(const int &window_width, const int &window_height)
    : width(window_width / GRID_CELL_WIDTH),
      height(window_height / GRID_CELL_HEIGHT),
      n_cells(width * height),
      grid(new unsigned char[n_cells]{0}),
      cell(sf::Vector2f(CELL_WIDTH, CELL_HEIGHT)),
      horizontalPath(sf::Vector2f(PATH_THICKNESS, CELL_HEIGHT)),
      verticalPath(sf::Vector2f(CELL_WIDTH, PATH_THICKNESS)) {
    cell.setFillColor(sf::Color::White);
    horizontalPath.setFillColor(sf::Color::White);
    verticalPath.setFillColor(sf::Color::White);

    srand(clock());
    cell_stack.push(rand() % n_cells);
    n_visited = 1;
}

Maze::~Maze() { delete[] grid; }

void Maze::step(sf::RenderWindow &window) {
    const int &t = cell_stack.top();
    std::vector<Direction> next_direction;

    cell.setPosition(XY(0, 0));
    window.draw(cell);

    if (t >= width && !grid[t - width]) next_direction.push_back(N);
    if (t % width < width - 1 && !grid[t + 1]) next_direction.push_back(E);
    if (t / width < height - 1 && !grid[t + width]) next_direction.push_back(S);
    if (t % width && !grid[t - 1]) next_direction.push_back(W);

    if (!next_direction.empty()) {
        switch (next_direction[rand() % next_direction.size()]) {
            case N:
                grid[t] |= N;
                verticalPath.setPosition(XY(0, -PATH_THICKNESS));
                window.draw(verticalPath);
                grid[t - width] |= S;
                cell_stack.push(t - width);
                break;
            case E:
                grid[t] |= E;
                horizontalPath.setPosition(XY(CELL_WIDTH, 0));
                window.draw(horizontalPath);
                grid[t + 1] |= W;
                cell_stack.push(t + 1);
                break;
            case S:
                grid[t] |= S;
                verticalPath.setPosition(XY(0, CELL_HEIGHT));
                window.draw(verticalPath);
                grid[t + width] |= N;
                cell_stack.push(t + width);
                break;
            case W:
                grid[t] |= W;
                horizontalPath.setPosition(XY(-PATH_THICKNESS, 0));
                window.draw(horizontalPath);
                grid[t - 1] |= E;
                cell_stack.push(t - 1);
                break;
        }
        ++n_visited;
    } else {
        cell_stack.pop();
    }
}
