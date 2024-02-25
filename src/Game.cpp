#include "Game.h"

Game::Game()
    : window(sf::VideoMode::getDesktopMode(), "Amaze", sf::Style::Fullscreen),
      maze(window.getSize().x, window.getSize().y) {}

void Game::loop() {
    sf::Event event;
    window.clear();
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed &&
                 event.key.code == sf::Keyboard::Escape)) {
                window.close();
                return;
            }
        }
        maze.step(window);
        window.display();
    }
}
