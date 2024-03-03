#pragma once

#include <stack>

#include "Renderer.hpp"

class Maze {
   private:
    const int width;
    const int height;
    const int n_cells;
    unsigned char *const grid;
    Renderer &renderer;

    std::stack<int> cell_stack;

   public:
    Maze(int width, int height, Renderer &renderer);
    ~Maze();

    bool isComplete();
    void step();
};

inline bool Maze::isComplete() { return cell_stack.empty(); }
