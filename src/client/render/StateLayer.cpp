#include "StateLayer.h"

using namespace std;
using namespace render;


StateLayer::StateLayer(state::State &currentState, sf::RenderWindow & window, sf::Font & font) : currentState(
        currentState), window(window), font(font) {
    if (!font.loadFromFile("./../res/Police/ARIAL.TTF")) {
        cout << "Error load file ARIAL.TTF." << endl;
    }

}

sf::Font &StateLayer::getFont() {
    return this->font;
}

sf::RenderWindow & StateLayer::getWindow() {
    return this->window;
}

