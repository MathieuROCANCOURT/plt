#include "AllButtons.h"
#include <utility>

using namespace render;
using namespace std;

AllButtons::AllButtons() : listButtons() {

}

AllButtons::AllButtons(vector<Button *> listButtons) : listButtons(std::move(listButtons)) {

}

void AllButtons::addButton(Button * button) {
    this->listButtons.push_back(button);
}

void AllButtons::removeButton(Button * button) {
    auto it = std::remove(this->listButtons.begin(), this->listButtons.end(), button);
    listButtons.erase(it, listButtons.end());
}

Button *AllButtons::getFocus() {
    for (auto button: this->listButtons) {
        if (button->getRectangle().getFillColor() == sf::Color::Green){
            return button;
        }
    }
    return nullptr;
}

void AllButtons::setFocus(sf::Vector2i cursorPos) {
    for (auto button: this->listButtons) {
        sf::FloatRect textRect = button->getRectangle().getGlobalBounds();
        if (textRect.contains(sf::Vector2f(cursorPos))) {
            if (this->selectedButton != nullptr) {
                this->selectedButton->getRectangle().setFillColor(this->selectedButton->getButtonColor()); // On remet à sa couleur d'origine
            }
            this->selectedButton = button;
            this->selectedButton->getRectangle().setFillColor(sf::Color::Green); // On change sa couleur en vert
        }
    }
}

void AllButtons::draw(sf::RenderWindow & window) {
    for (Button * button: this->listButtons) {
        button->draw(window);
    }
}

AllButtons::~AllButtons() {
    this->listButtons.clear();
}
