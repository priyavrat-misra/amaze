#include "Renderer.hpp"

#define DIM(W, H) sf::Vector2f(scale * W, scale * H)
#define POS(DX, DY) scale * (x + DX), scale * (y + DY)
#define CELL_THICKNESS (1 - 2 * PATH_THICKNESS)
#define PATH_THICKNESS 0.1

Renderer::Renderer(sf::RenderWindow &window, int scale)
    : window(window),
      scale(scale),
      cell(DIM(CELL_THICKNESS, CELL_THICKNESS)),
      hPath(DIM(2 * PATH_THICKNESS, CELL_THICKNESS)),
      vPath(DIM(CELL_THICKNESS, 2 * PATH_THICKNESS)) {}

void Renderer::drawCell(int x, int y) {
    cell.setPosition(POS(PATH_THICKNESS, PATH_THICKNESS));
    window.draw(cell);
}

void Renderer::drawPath(int x, int y, const Direction &direction) {
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
