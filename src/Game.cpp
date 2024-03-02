#include "Game.hpp"

#define SCALE 10

Game::Game()
    : window(sf::VideoMode(1280, 720), "Amaze", sf::Style::Close),
      renderer(window, SCALE),
      maze(window.getSize().x / SCALE, window.getSize().y / SCALE, renderer) {
    window.setFramerateLimit(120); 
    window.setActive(true);
}

void Game::loop() {
    sf::Event event;
    window.clear(sf::Color::Black);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed &&
                 event.key.code == sf::Keyboard::Escape)) {
                window.close();
                return;
            }
        }
        if (!maze.isComplete()) {
            maze.step();
            window.display();
        }
    }
}
