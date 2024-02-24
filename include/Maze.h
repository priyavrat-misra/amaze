#pragma once

#include <stack>

class Maze {
   private:
    unsigned char *const grid;
    const int width;
    const int height;
    const int n_cells;

    std::stack<int> cell_stack;
    int n_visited;

   private:
    void generate();

   public:
    Maze(const int &width, const int &height);
    ~Maze();
};
