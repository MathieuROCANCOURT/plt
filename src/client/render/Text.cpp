#include <iostream>
#include <utility>
#include "Text.h"

using namespace std;

render::Text::Text(string text, float posXtext, float posYtext, int characterSize, sf::Color colorText) :
        text(std::move(text)),
        posXtext(posXtext),
        posYtext(posYtext),
        characterSize(characterSize),
        colorText(colorText){
    sf::Font font;
    if (!font.loadFromFile("./../res/Police/ARIAL.TTF")) {
        cout << "Error load file ARIAL.TTF." << endl;
    }
    this->blocText = sf::Text(this->text, font, this->characterSize);
    this->blocText.setFillColor(this->colorText);
    this->blocText.setPosition(this->posXtext, this->posYtext);
}
sf::Text render::Text::getText() {
    return this->blocText;
}
