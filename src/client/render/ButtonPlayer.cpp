#include "ButtonPlayer.h"

#include <utility>

using namespace std;
using namespace render;

render::ButtonPlayer::ButtonPlayer(float sizeXButton, float sizeYButton, float posXButton, float posYButton,
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
    this->rectangle.setFillColor(sf::Color::Yellow);
    this->rectangle.setOutlineColor(sf::Color::Black);
    this->rectangle.setOutlineThickness(this->thicknessButton);

    this->textPlayer = sf::Text(this->text, this->font, this->characterSize);
    this->textPlayer.setFillColor(sf::Color::Black);
    this->textPlayer.setPosition(this->posXText, this->posYText);
}


sf::RectangleShape render::ButtonPlayer::getRectangle() {
    return this->rectangle;
}

sf::Text render::ButtonPlayer::getText() {
    return this->textPlayer;
}
sf::RectangleShape *render::ButtonPlayer::changePointer() {
    return &this->rectangle;
}
