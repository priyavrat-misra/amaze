#pragma once

#include <stack>

class Game;

class Maze {
   private:
    const int width;
    const int height;
    unsigned char *const grid;
    Game *const game;

    std::stack<int> cell_stack;

   public:
    Maze(int width, int height, Game *const game);
    ~Maze();

    bool isComplete() const;
    void step();
};

inline bool Maze::isComplete() const { return cell_stack.empty(); }
