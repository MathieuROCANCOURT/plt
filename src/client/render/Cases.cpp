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
    this->square = sf::CircleShape(this->radius, this->pointCount);
    this->square.setFillColor(this->fillColor);
    this->square.setOutlineColor(this->caseColor);
    this->square.setOutlineThickness(this->thickness);
    this->square.move(this->posX, this->posY);
    this->square.rotate(this->rotate);
}

sf::CircleShape Cases::getSquare() {
    return this->square;
}

void Cases::setFillColor(sf::Color changeColor) {
    this->square.setFillColor(changeColor);
}

Cases::~Cases() {
    delete this;
}
