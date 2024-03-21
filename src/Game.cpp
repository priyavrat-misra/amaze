#include "Game.hpp"
#include "Maze.hpp"

#define DIM(W, H) sf::Vector2f(SCALE * W, SCALE * H)
#define POS(DX, DY) SCALE * (x + DX), SCALE * (y + DY)
#define CELL_THICKNESS (1 - 2 * PATH_THICKNESS)

#define PATH_THICKNESS 0.1
#define SCALE 20

Game::Game()
    : window(sf::VideoMode(1280, 720), "Amaze", sf::Style::Close),
      maze(window.getSize().x / SCALE, window.getSize().y / SCALE, this),
      cell(DIM(CELL_THICKNESS, CELL_THICKNESS)),
      hPath(DIM(2 * PATH_THICKNESS, CELL_THICKNESS)),
      vPath(DIM(CELL_THICKNESS, 2 * PATH_THICKNESS)) {
    window.setFramerateLimit(120); 
    window.setVerticalSyncEnabled(true); 
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

void Game::drawCell(int x, int y) {
    cell.setPosition(POS(PATH_THICKNESS, PATH_THICKNESS));
    window.draw(cell);
}

void Game::drawPath(int x, int y, const Direction &direction) {
    switch (direction) {
        case N:
            vPath.setPosition(POS(PATH_THICKNESS, -PATH_THICKNESS));
            window.draw(vPath);
            break;
        case E:
            hPath.setPosition(POS(PATH_THICKNESS + CELL_THICKNESS, PATH_THICKNESS));
            window.draw(hPath);
            break;
        case S:
            vPath.setPosition(POS(PATH_THICKNESS, PATH_THICKNESS + CELL_THICKNESS));
            window.draw(vPath);
            break;
        case W:
            hPath.setPosition(POS(-PATH_THICKNESS, PATH_THICKNESS));
            window.draw(hPath);
            break;
    }
}
