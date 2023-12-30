#include "Button.h"

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

    this->textPlayer = *new Text(this->text, this->posXText, this->posYText, this->characterSize,
                                 sf::Color::Black);
}

Text & Button::getText() {
    return this->textPlayer;
}

sf::RectangleShape &Button::getRectangle() {
    return this->rectangle;
}

Button *Button::click(int x, int y) {
    sf::FloatRect textRect = this->getRectangle().getGlobalBounds();
    static Button *selectedText = nullptr;
    if (textRect.contains(float(x), float(y))) {
        if (selectedText != nullptr) {
            selectedText->getRectangle().setFillColor(sf::Color::Yellow); // On remet sa couleur en jaune
        }
        selectedText = this;
        selectedText->getRectangle().setFillColor(sf::Color::Green); // On change sa couleur en vert
    }
    return this;
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(this->getRectangle());
    window.draw(this->getText().getText());
}
