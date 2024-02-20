#pragma once

#include <unordered_map>

class Maze {
   private:
    unsigned char *const grid;
    const int width;
    const int height;

    enum Direction : unsigned char {
        N = 0x01,
        E = 0x02,
        S = 0x04,
        W = 0x08,
    };

    const std::unordered_map<Direction, const std::pair<int, int>> coordinates = {
        {N, {0, -1}},
        {E, {1, 0}},
        {S, {0, 1}},
        {W, {-1, 0}}
    };

   private:
    void generate(const int &x, const int &y);

   public:
    Maze(const int &width, const int &height);
    ~Maze();
};
