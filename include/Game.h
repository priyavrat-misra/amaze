#pragma once

#include <SFML/Graphics.hpp>

#include "Direction.h"
#include "Maze.h"

class Game {
   private:
    sf::RenderWindow window;
    Maze maze;

   public:
    Game();

    void loop();
};
