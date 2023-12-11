#include <iostream>
#include "Render.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State &currentState) : currentState(currentState) {
    this->gameInfo = *new GameInformation();
    this->gameBoard = *new GameBoard(this->currentState.getNbplayer());


    this->window.create(sf::VideoMode(this->gameBoard.getSizeBoard().x * 2, this->gameBoard.getSizeBoard().y),
                        "Monopoly");
    this->window.setVerticalSyncEnabled(true);
}

sf::RenderWindow &Render::getWindow() {
    return this->window;
}

void Render::draw() {
    this->window.clear(sf::Color::White);
    this->getWindow().draw(this->gameBoard.getSpriteBoard());

    this->getWindow().display();
}

void Render::debt(int player) {

}

Render::~Render() {
    delete this;
}
