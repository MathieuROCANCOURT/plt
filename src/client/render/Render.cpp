#include "Render.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State &currentState) : currentState(currentState) {
    this->currentState.getListPlayer();
    this->gameBoard = *new GameBoard(this->currentState.getNbPlayer());
    this->gameInfo = *new GameInformation(this->gameBoard.getSizeBoard(), this->currentState.getNbPlayer());


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

void Render::draw(const sf::Vector2i cursorPos) {
    static vector<Cases *> listCasesPlayer;
    static vector<Cases *> listCasesBank = this->gameInfo.CreateCases(vector<Cases *>(),
                                                                      uint(this->gameBoard.getSizeBoard().y * 0.47));
    this->window.clear(sf::Color::White);

    /* Draw board and tokens */
    this->window.draw(this->gameBoard.getSpriteBoard());
    for (auto token: this->gameBoard.getListToken()) {
        this->window.draw(token->getSprite());
    }

    /* Cases Bank */
    for (auto cases: listCasesBank) {
        this->window.draw(cases->getSquare());
    }

    this->gameInfo.hoverCase(cursorPos, listCasesPlayer, this->window);
    this->gameInfo.hoverCase(cursorPos, listCasesBank, this->window);

    /* Buttons Players */
    for (auto buttonP: this->gameInfo.getListButtonPlayer()) {
        if (buttonP->getRectangle().getFillColor() == sf::Color::Green) {
            listCasesPlayer = this->gameInfo.CreateCases(listCasesPlayer,
                                                         this->gameBoard.getSizeBoard().y * 0.14);
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
