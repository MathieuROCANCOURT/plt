//
// Created by mathieu on 27/11/23.
//
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Cases.h"

render::Cases::Cases(float posX, float posY, sf::Color caseColor, float radius, int pointCount, sf::Color fillColor,
                     float thickness, float rotate) : posX(posX),
                                                      posY(posY),
                                                      caseColor(caseColor),
                                                      radius(radius),
                                                      pointCount(pointCount),
                                                      fillColor(fillColor),
                                                      thickness(thickness),
                                                      rotate(rotate) {
    sf::CircleShape square(this->radius, this->pointCount);
    square.setFillColor(this->fillColor);
    square.setOutlineColor(this->caseColor);
    square.setOutlineThickness(this->thickness);
    square.move(this->posX, this->posY);
    square.rotate(this->rotate);

}

render::Cases::~Cases() {
    delete this;
}
