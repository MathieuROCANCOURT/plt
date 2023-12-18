#include <iostream>
#include <utility>
#include "Text.h"

using namespace std;
using namespace render;

Text::Text(string text, float posXtext, float posYtext, int characterSize, sf::Color colorText) :
        text(std::move(text)),
        posXtext(posXtext),
        posYtext(posYtext),
        characterSize(characterSize),
        colorText(colorText){
    sf::Font font;
    if (!font.loadFromFile("./../res/Police/ARIAL.TTF")) {
        cout << "Error load file ARIAL.TTF." << endl;
    }
    this->blocText.setString(this->text);
    this->blocText.setCharacterSize(this->characterSize);
    this->blocText.setFont(font);
    this->blocText.setFillColor(this->colorText);
    this->blocText.move(this->posXtext, this->posYtext);
}

sf::Text Text::getText() {
    return this->blocText;
}
