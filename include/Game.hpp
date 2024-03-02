#pragma once

#include <SFML/Graphics.hpp>

#include "Maze.hpp"
#include "Renderer.hpp"

class Game {
   private:
    sf::RenderWindow window;
    Renderer renderer;
    Maze maze;

   public:
    Game();

    void loop();
};
