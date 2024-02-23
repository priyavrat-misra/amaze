#include <iostream>

#include "maze.h"

using namespace std;

int main(int argc, const char *argv[]) {
    int width;
    int height;

    if (argc == 3) {
        width = atoi(argv[1]);
        height = atoi(argv[2]);
        if (!(width > 0 && height > 0)) {
            cerr << "Invalid input." << endl;
            return EXIT_FAILURE;
        }
    } else {
        cout << "Enter the width and the height: ";
        if (!(cin >> width >> height && width > 0 && height > 0)) {
            cerr << "Invalid input." << endl;
            return EXIT_FAILURE;
        }
    }

    Maze maze(width, height);
    cout << "A " << width << " x " << height << " grid created." << endl;

    return EXIT_SUCCESS;
}
