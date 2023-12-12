#include <iostream>
#include "Render.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State &currentState) : currentState(currentState) {
    this->gameBoard = *new GameBoard(this->currentState.getNbplayer());
    this->gameInfo = *new GameInformation(this->gameBoard.getSizeBoard(), 6);


    this->window.create(sf::VideoMode(this->gameBoard.getSizeBoard().x * 2, this->gameBoard.getSizeBoard().y),
                        "Monopoly");
    this->window.setVerticalSyncEnabled(true);
}

sf::RenderWindow &Render::getWindow() {
    return this->window;
}

void Render::draw() {
    this->window.clear(sf::Color::White);
    this->window.draw(this->gameBoard.getSpriteBoard());
    for (auto button: this->gameInfo.getListButton()) {
        this->window.draw(button.getRectangle());
        //this->window.draw(button.getText().getText());
    }
    /*for (auto texts: this->gameInfo.getListText()) {
        this->window.draw(texts.getText());
    }*/

    this->window.display();
}

void Render::debt(int player) {

}

Render::~Render() {
    delete this;
}
