//
// Created by mathieu on 27/11/23.
//
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Cases.h"

render::Cases::Cases(float posX, float posY, sf::Color caseColor, float radius, int pointCount, sf::Color fillColor,
                     float thickness, float rotate) {
    sf::CircleShape square(radius, pointCount);
    square.setFillColor(fillColor);
    square.setOutlineColor(caseColor);
    square.setOutlineThickness(thickness);
    square.move(posX, posY);
    square.rotate(rotate);

}

