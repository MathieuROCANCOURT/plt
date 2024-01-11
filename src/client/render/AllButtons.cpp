#include "AllButtons.h"
#include <utility>

using namespace render;
using namespace std;

AllButtons::AllButtons() : listButtons() {

}

AllButtons::AllButtons(vector<Button *> listButtons) : listButtons(std::move(listButtons)) {

}

std::vector<Button *> AllButtons::getListButtons() {
    return this->listButtons;
}

Button *AllButtons::getFocus() {
    for (auto button: this->listButtons) {
        if (button->getRectangle().getFillColor() == sf::Color::Green) {
            return button;
        }
    }
    return nullptr;
}

Button *AllButtons::getHover() {
    for (auto button: this->listButtons) {
        if (button->getRectangle().getFillColor() == sf::Color::Cyan) {
            return button;
        }
    }
    return nullptr;
}

void AllButtons::setFocus(sf::Vector2i cursorPos, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        for (auto button: this->listButtons) {
            sf::FloatRect textRect = button->getRectangle().getGlobalBounds();
            if (textRect.contains(sf::Vector2f(cursorPos))) {
                if (this->selectedButton != nullptr) {
                    this->selectedButton->getRectangle().setFillColor(
                            this->selectedButton->getButtonColor()); // On remet à sa couleur d'origine
                }
                this->selectedButton = button;
                this->selectedButton->getRectangle().setFillColor(sf::Color::Green); // On change sa couleur en vert
            }
        }
    }
}

void AllButtons::setHover(sf::Vector2i cursorPos) {
    for (auto *button: this->listButtons) {
        button->hover(cursorPos);
    }
}

void AllButtons::addButton(Button *button) {
    this->listButtons.push_back(button);
}

void AllButtons::removeButton(Button *button) {
    auto it = std::remove(this->listButtons.begin(), this->listButtons.end(), button);
    this->listButtons.erase(it, this->listButtons.end());
}

void AllButtons::changeListButton(vector<Button *> listButtonChange) {
    for (auto button: this->listButtons){
        this->removeButton(button);
    }
    this->listButtons = std::move(listButtonChange);
    this->selectedButton = nullptr;
}

void AllButtons::draw(sf::RenderWindow &window, sf::Vector2i cursorPos, sf::Event event) {
    this->setFocus(cursorPos, event);
    this->setHover(cursorPos);

    for (Button *button: this->listButtons) {
        button->draw(window);
    }
}

AllButtons::~AllButtons() {
    this->listButtons.clear();
}
