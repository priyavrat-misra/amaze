#pragma once

#include <SFML/Graphics.hpp>

#include "Maze.hpp"

class Game {
   private:
    sf::RenderWindow window;
    Maze maze;

   public:
    Game();

    void loop();
};
