#pragma once

class Maze {
   private:
    unsigned char *const grid;
    const int width;
    const int height;
    const int num_cells;

    enum Direction : unsigned char {
        N = 0x31,
        E = 0x42,
        S = 0x14,
        W = 0xC8,
    };

   private:
    inline int offset(const int &x, const int &y) { return y * width + x; }

    inline bool isValidIndex(const int &x, const int &y) {
        return x > -1 && x < width && y > -1 && y < height;
    }

    void generate(const int &x, const int &y);

   public:
    Maze(const int &width, const int &height);
    ~Maze();
};
