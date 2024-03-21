#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.hpp"
#include "Maze.hpp"

class Game {
   private:
    sf::RenderWindow window;
    Maze maze;
    sf::RectangleShape cell;
    sf::RectangleShape hPath;
    sf::RectangleShape vPath;

   public:
    Game();

    void loop();
    void drawCell(int x, int y);
    void drawPath(int x, int y, const Direction &direction);
};
