#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.hpp"

class Renderer {
   private:
    sf::RenderWindow &window;
    const int scale;
    sf::RectangleShape cell;
    sf::RectangleShape hPath;
    sf::RectangleShape vPath;

   public:
    Renderer(sf::RenderWindow &window, int scale);

    void drawCell(int x, int y);
    void drawPath(int x, int y, const Direction &direction);
};
