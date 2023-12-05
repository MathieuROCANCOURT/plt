//
// Created by mathieu on 04/12/23.
//
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace std;
using namespace render;

render::Button::Button(float sizeXButton, float sizeYButton, float posXButton, float posYButton,
                                 const sf::Font &font, std::string text, float posXText, float posYText,
                                 int characterSize, sf::Color colorText, float thicknessButton, sf::Color buttonColor,
                                 sf::Color buttonOutline) : sizeXButton(sizeXButton),
                                                           sizeYButton(sizeYButton),
                                                           posXButton(posXButton),
                                                           posYButton(posYButton),
                                                           font(font),
                                                           text(std::move(text)),
                                                           posXText(posXText),
                                                           posYText(posYText),
                                                           characterSize(characterSize),
                                                           colorText(colorText),
                                                           thicknessButton(thicknessButton),
                                                           buttonColor(buttonColor),
                                                           buttonOutline(buttonOutline) {
    this->rectangle = sf::RectangleShape(sf::Vector2f(this->sizeXButton, this->sizeYButton));
    this->rectangle.setPosition(this->posXButton, this->posYButton);
    this->rectangle.setFillColor(this->buttonColor);
    this->rectangle.setOutlineColor(this->buttonOutline);
    this->rectangle.setOutlineThickness(this->thicknessButton);

    this->textPlayer = sf::Text(this->text, this->font, this->characterSize);
    this->textPlayer.setFillColor(this->colorText);
    this->textPlayer.setPosition(this->posXText, this->posYText);

}
sf::RectangleShape render::Button::getRectangle() {
    return this->rectangle;
}

/*sf::RectangleShape render::Button::setRectangle(sf::RectangleShape rectangle) {
    return rectangle;
}*/

sf::Text render::Button::getText() {
    return this->textPlayer;
}

