#include "Cases.h"

using namespace std;
using namespace render;

Cases::Cases(float posX, float posY, sf::Color caseColor, float radius, int pointCount, sf::Color fillColor,
             float thickness, float rotate) : posX(posX),
                                              posY(posY),
                                              caseColor(caseColor),
                                              radius(radius),
                                              pointCount(pointCount),
                                              fillColor(fillColor),
                                              thickness(thickness),
                                              rotate(rotate) {
    this->square.setSize(sf::Vector2f(40, 40));
    this->square.rotate(45);
    this->square.setFillColor(this->fillColor);
    this->square.setOutlineColor(this->caseColor);
    this->square.setOutlineThickness(this->thickness);
    this->square.setPosition(this->posX, this->posY);
    this->square.rotate(this->rotate);
}

sf::RectangleShape Cases::getSquare() {
    return this->square;
}

void Cases::setFillColor(sf::Color changeColor) {
    this->square.setFillColor(changeColor);
}

void Cases::draw(sf::RenderWindow &window) {
    window.draw(this->square);
}

Cases::~Cases() = default;
