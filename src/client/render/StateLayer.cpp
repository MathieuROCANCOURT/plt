#include <iostream>
#include "StateLayer.h"

using namespace std;
using namespace render;


StateLayer::StateLayer(state::State &currentState, sf::RenderWindow & window, sf::Font & font) : currentState(
        currentState), window(window), font(font) {
    if (!font.loadFromFile("./../res/Police/ARIAL.TTF")) {
        std::cout << "Error load file ARIAL.TTF." << endl;
    }

}

sf::RenderWindow &StateLayer::getWindow() const {
    return this->window;
}

sf::Font &StateLayer::getFont() const {
    return this->font;
}



