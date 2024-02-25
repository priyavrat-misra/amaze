#pragma once

#include <SFML/Graphics.hpp>
#include <stack>

class Maze {
   private:
    const int width;
    const int height;
    const int n_cells;
    unsigned char *const grid;

    std::stack<int> cell_stack;
    int n_visited;

    sf::RectangleShape cell;
    sf::RectangleShape horizontalPath;
    sf::RectangleShape verticalPath;

   public:
    Maze(const int &width, const int &height);
    ~Maze();

    void step(sf::RenderWindow &window);
};
