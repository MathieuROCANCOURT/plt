#include "TextField.h"

#include <utility>

using namespace render;
using namespace std;

TextField::TextField(float sizeXButton, float sizeYButton, float posXButton, float posYButton, string text,
                     sf::Color buttonColor, sf::Color buttonOutline, float thicknessButton, sf::Color colorText,
                     int characterSize) : Button(sizeXButton,
                                                 sizeYButton,
                                                 posXButton,
                                                 posYButton,
                                                 std::move(text),
                                                 posXButton + 2,
                                                 posYButton + 2,
                                                 buttonColor,
                                                 buttonOutline,
                                                 thicknessButton,
                                                 colorText,
                                                 characterSize) {
    this->hasFocus = false;

}

void TextField::setFocus(sf::Vector2i cursorPos) {
    this->hasFocus = this->getRectangle().getGlobalBounds().contains(sf::Vector2f(cursorPos));
    if (this->hasFocus) {
        this->getRectangle().setOutlineColor(sf::Color::Blue); // On met sa couleur en bleu
    } else {
        this->getRectangle().setOutlineColor(sf::Color::Black); // On change sa couleur en noir
    }
}

void TextField::handleInput(sf::Event event) {
    if (this->hasFocus && event.type == sf::Event::TextEntered){
        if (event.text.unicode == 8) {   // Delete key
            this->text = this->text.substr(0, this->text.size() - 1);
            this->getText()->setStringText(this->text);
        } else if (this->text.size() < 8) {
            this->text += static_cast<char>(event.text.unicode);
            this->getText()->setStringText(this->text);
        }
    }
}

