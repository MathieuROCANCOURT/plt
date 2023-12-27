#include "Render.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State &currentState) : currentState(currentState) {
    this->gameBoard = *new GameBoard(this->currentState.getNbPlayer());
    this->gameInfo = new GameInformation(this->gameBoard.getSizeBoard(), (int) currentState.getNbPlayer(),
                                         currentState.getBank());

    this->window.create(sf::VideoMode(this->gameBoard.getSizeBoard().x * 2, this->gameBoard.getSizeBoard().y),
                        "Monopoly");
    this->window.setVerticalSyncEnabled(true);
}

state::State &Render::getCurrentState() const {
    return this->currentState;
}

GameInformation *Render::getGameInfo() {
    return this->gameInfo;
}

sf::RenderWindow &Render::getWindow() {
    return this->window;
}

void Render::draw(const sf::Vector2i cursorPos) {
    this->window.clear(sf::Color::White);

    this->gameBoard.draw(this->window);
    this->gameInfo->draw(this->window, cursorPos);

    this->window.display();
}

void Render::debt(int player) {

}

Render::~Render() {
    delete this;
}
