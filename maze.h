#pragma once

class Maze {
   private:
    unsigned char *const grid;
    const int width;
    const int height;
    const int n_cells;

    enum Direction : unsigned char {
        N = 0x01,
        E = 0x02,
        S = 0x04,
        W = 0x08,
    };

   private:
    void generate(const int &i);

   public:
    Maze(const int &width, const int &height);
    ~Maze();
};
