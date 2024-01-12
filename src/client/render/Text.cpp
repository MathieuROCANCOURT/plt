#include "Text.h"
#include "config.h"
#include <utility>

using namespace std;
using namespace render;

Text::Text() {

}

Text::Text(string text, float posXtext, float posYtext, int characterSize, sf::Color colorText) :
        text(std::move(text)),
        posXtext(posXtext),
        posYtext(posYtext),
        characterSize(characterSize),
        colorText(colorText){
    string path = RES_DIR;
    if (!font.loadFromFile(path + "Police/ARIAL.TTF")) {
        perror("Error load file ARIAL.TTF.");
    }
    this->blocText.setString(this->text);
    this->blocText.setCharacterSize(this->characterSize);
    this->blocText.setFont(font);
    this->blocText.setFillColor(this->colorText);
    this->blocText.move(this->posXtext, this->posYtext);
}

sf::Text & Text::getText() {
    return this->blocText;
}

std::string Text::getStringText() {
    return this->text;
}

void Text::setStringText(string switchText){
    this->text = std::move(switchText);
    this->blocText.setString(this->text);
}

void Text::draw(sf::RenderWindow & window) {
    window.draw(this->blocText);
}
