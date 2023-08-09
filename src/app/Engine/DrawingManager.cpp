#include <iostream>

#include "Managers/DrawingManager.h"


DrawingManager::DrawingManager(DrawingCanvas& canvas) : m_canvas(canvas) {}

void DrawingManager::draw() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::cout << "Pressed left mouse button. Click Coordinates: " << sf::Mouse::getPosition(m_canvas.getWindow()).x << " " << sf::Mouse::getPosition(m_canvas.getWindow()).y;
        sf::Vertex line[] = {
            sf::Vertex(static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_canvas.getWindow()))),
            sf::Vertex(static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_canvas.getWindow())))
        };
        m_canvas.getWindow().draw(line, 2, sf::Lines);
    }
}
