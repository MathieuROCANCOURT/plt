#include <iostream>
#include "Render.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State &currentState) : currentState(currentState) {
    this->gameBoard = *new GameBoard(this->currentState.getNbPlayer());
    this->gameInfo = *new GameInformation(this->gameBoard.getSizeBoard(), 6);


    this->window.create(sf::VideoMode(this->gameBoard.getSizeBoard().x * 2, this->gameBoard.getSizeBoard().y),
                        "Monopoly");
    this->window.setVerticalSyncEnabled(true);
}

GameInformation &Render::getGameInfo() {
    return this->gameInfo;
}

sf::RenderWindow &Render::getWindow() {
    return this->window;
}

void Render::draw() {
    static vector<Cases *> listCasesPlayer, listCasesBank = this->gameInfo.CreateCases(0, listCasesBank, this->gameBoard.getSizeBoard() + sf::Vector2u (0, this->gameBoard.getSizeBoard().y * 4.8));
    this->window.clear(sf::Color::White);
    this->window.draw(this->gameBoard.getSpriteBoard());

    for (auto token: this->gameBoard.getListToken()) {
        this->window.draw(token->getSprite());
    }

    /* Cases Bank */
    for (auto cases: listCasesBank) {
        this->window.draw(cases->getSquare());
    }

    /* Buttons Players */
    for (auto buttonP: this->gameInfo.getListButtonPlayer()) {
        if (buttonP->getRectangle().getFillColor() == sf::Color::Green) {
            listCasesPlayer = this->gameInfo.CreateCases(1, listCasesPlayer, this->gameBoard.getSizeBoard());
        }
        for (auto cases: listCasesPlayer) {
            this->window.draw(cases->getSquare());
        }
        this->window.draw(buttonP->getRectangle());
        this->window.draw(buttonP->getText().getText());
    }
    /* Buttons Actions */
    for (auto buttonA: this->gameInfo.getListButtonAction()) {
        this->window.draw(buttonA->getRectangle());
        this->window.draw(buttonA->getText().getText());
    }
    /* Draw text */
    for (auto texts: this->gameInfo.getListText()) {
        this->window.draw(texts.getText());
    }
    this->window.display();
}

void Render::debt(int player) {

}

Render::~Render() {
    delete this;
}
