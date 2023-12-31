#include "Button.h"
#include "Token.h"

using namespace std;
using namespace render;

Button::Button(float sizeXButton, float sizeYButton, float posXButton, float posYButton, string text,
               float posXText, float posYText, sf::Color buttonColor, sf::Color buttonOutline, float thicknessButton,
               sf::Color colorText, int characterSize) : sizeXButton(sizeXButton),
                                                         sizeYButton(sizeYButton),
                                                         posXButton(posXButton),
                                                         posYButton(posYButton),
                                                         text(std::move(text)),
                                                         posXText(posXText),
                                                         posYText(posYText),
                                                         buttonColor(buttonColor),
                                                         buttonOutline(buttonOutline),
                                                         thicknessButton(thicknessButton),
                                                         colorText(colorText),
                                                         characterSize(characterSize) {
    this->rectangle = sf::RectangleShape(sf::Vector2f(this->sizeXButton, this->sizeYButton));
    this->rectangle.setPosition(this->posXButton, this->posYButton);
    this->rectangle.setFillColor(this->buttonColor);
    this->rectangle.setOutlineColor(this->buttonOutline);
    this->rectangle.setOutlineThickness(this->thicknessButton);

    this->textPlayer = new Text(this->text, this->posXText, this->posYText, this->characterSize,
                                sf::Color::Black);
}

Button::Button(state::Token chooseToken, float sizeXButton, float sizeYButton, float posXButton, float posYButton,
               sf::Color buttonOutline, float thicknessButton) : sizeXButton(sizeXButton),
                                                                 sizeYButton(sizeYButton),
                                                                 posXButton(posXButton),
                                                                 posYButton(posYButton),
                                                                 buttonColor(sf::Color::White),
                                                                 buttonOutline(buttonOutline),
                                                                 thicknessButton(thicknessButton){
    this->rectangle = sf::RectangleShape(sf::Vector2f(this->sizeXButton, this->sizeYButton));
    this->rectangle.setPosition(this->posXButton, this->posYButton);
    this->rectangle.setFillColor(this->buttonColor);
    this->rectangle.setOutlineColor(this->buttonOutline);
    this->rectangle.setOutlineThickness(this->thicknessButton);

    this->token = new Token(chooseToken);
    this->token->posMove(sf::Vector2f(this->posXButton, this->posYButton));
}

sf::Color Button::getButtonColor() {
    return this->buttonColor;
}

Text *Button::getText() {
    return this->textPlayer;
}

sf::RectangleShape &Button::getRectangle() {
    return this->rectangle;
}

Token *Button::getToken() {
    return this->token;
}

void Button::select() {
    this->getRectangle().setFillColor(sf::Color::Green); // On met sa couleur en vert
}

void Button::deselect() {
    this->getRectangle().setFillColor(this->buttonColor); // On remet sa couleur d'origine
}

void Button::setFocus(sf::Vector2i cursorPos) {
    sf::FloatRect textRect = this->getRectangle().getGlobalBounds();
    if (textRect.contains(sf::Vector2f(cursorPos))) {
        this->select();
    } else {
        this->deselect();
    }
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(this->getRectangle());
    if (this->getText() != nullptr) {
        window.draw(this->getText()->getText());
    }
    if (this->token != nullptr) {
        this->token->draw(window);
    }
}

Button::~Button() {
    delete textPlayer;
    delete token;
}
