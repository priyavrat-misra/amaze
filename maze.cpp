#include <cstdlib>
#include <ctime>
#include <stack>
#include <vector>

#include "maze.h"

std::pair<int, int> operator+(const std::pair<int, int> &x,
                              const std::pair<int, int> &y) {
    return std::make_pair(x.first + y.first, x.second + y.second);
}

Maze::Maze(const int &width, const int &height)
    : grid(new unsigned char[width * height]{0}), width(width), height(height) {
    srand(clock());
    generate(rand() % width, rand() % height);
}

Maze::~Maze() { delete[] grid; }

void Maze::generate(const int &x, const int &y) {
    std::stack<std::pair<int, int>> cell_stack;
    cell_stack.push({x, y});
    int n_cells = width * height;
    int n_visited = 1;

    auto offset = [&cell_stack, this](const auto &coordinate) {
        return (cell_stack.top().second + coordinate.second) * width +
               (cell_stack.top().first + coordinate.first);
    };

    while (n_visited < n_cells) {
        const auto &[xt, yt] = cell_stack.top();
        std::vector<Direction> next_direction;
        if (yt > 0 && !offset(coordinates.at(N)))
            next_direction.push_back(N);
        if (xt < width - 1 && !offset(coordinates.at(E)))
            next_direction.push_back(E);
        if (yt < height - 1 && !offset(coordinates.at(S)))
            next_direction.push_back(S);
        if (x > 0 && !offset(coordinates.at(W)))
            next_direction.push_back(W);

        if (!next_direction.empty()) {
            switch (next_direction[rand() % next_direction.size()]) {
                case N:
                    grid[offset(std::make_pair(0, 0))] |= N;
                    grid[offset(coordinates.at(N))] |= S;
                    cell_stack.push(cell_stack.top() + coordinates.at(N));
                    break;
                case E:
                    grid[offset(std::make_pair(0, 0))] |= E;
                    grid[offset(coordinates.at(E))] |= W;
                    cell_stack.push(cell_stack.top() + coordinates.at(E));
                    break;
                case S:
                    grid[offset(std::make_pair(0, 0))] |= S;
                    grid[offset(coordinates.at(S))] |= N;
                    cell_stack.push(cell_stack.top() + coordinates.at(S));
                    break;
                case W:
                    grid[offset(std::make_pair(0, 0))] |= W;
                    grid[offset(coordinates.at(W))] |= E;
                    cell_stack.push(cell_stack.top() + coordinates.at(W));
                    break;
            }
            ++n_visited;
        } else {
            cell_stack.pop();
        }
    }
}
