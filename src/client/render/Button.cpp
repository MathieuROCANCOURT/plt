#include "Button.h"

using namespace std;
using namespace render;

Button::Button(float sizeXButton, float sizeYButton, float posXButton, float posYButton, string text,
               float posXText, float posYText, int characterSize, sf::Color colorText, float thicknessButton,
               sf::Color buttonColor, sf::Color buttonOutline) : sizeXButton(sizeXButton),
                                                                 sizeYButton(sizeYButton),
                                                                 posXButton(posXButton),
                                                                 posYButton(posYButton),
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

    this->textPlayer = Text(this->text, this->posXText, this->posYText, this->characterSize,
                            sf::Color::Black);
}


sf::RectangleShape Button::getRectangle() {
    return this->rectangle;
}

Button * Button::click(int x, int y) {
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
