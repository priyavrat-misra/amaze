#include "Game.hpp"

Game::Game()
    : window(sf::VideoMode::getDesktopMode(), "Amaze", sf::Style::Fullscreen),
      maze(window.getSize().x, window.getSize().y) {
    window.setFramerateLimit(16); 
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
            maze.step(window);
            window.display();
        }
    }
}
