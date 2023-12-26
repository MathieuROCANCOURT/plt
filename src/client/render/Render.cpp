#include "Render.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State &currentState) : currentState(currentState){
    this->gameBoard = *new GameBoard(this->currentState.getNbPlayer());
    this->gameInfo = new GameInformation(this->gameBoard.getSizeBoard(), (int) currentState.getNbPlayer(), currentState.getBank());

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
    static vector<Cases *> listCasesPlayer;
    static vector<Cases *> listCasesBank = this->gameInfo->CreateCases(vector<Cases *>(),
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
    this->gameInfo->hoverCase(cursorPos, listCasesPlayer, this->window);
    this->gameInfo->hoverCase(cursorPos, listCasesBank, this->window);

    /* Draw texts and sprite house and apart */
    this->window.draw(this->gameInfo->getBankInformation()->getSpriteApart());
    this->window.draw(this->gameInfo->getBankInformation()->getSpriteHostel());
    this->window.draw(this->gameInfo->getBankInformation()->getTextBank().getText());
    this->window.draw(this->gameInfo->getBankInformation()->getTextApart().getText());
    this->window.draw(this->gameInfo->getBankInformation()->getTextHostel().getText());


    /* Buttons Players */
    for (auto buttonP: this->gameInfo->getListButtonPlayer()) {
        if (buttonP->getRectangle().getFillColor() == sf::Color::Green) {
            listCasesPlayer = this->gameInfo->CreateCases(listCasesPlayer,
                                                         this->gameBoard.getSizeBoard().y * 0.14);
        }
        for (auto cases: listCasesPlayer) {
            this->window.draw(cases->getSquare());
        }
        this->window.draw(buttonP->getRectangle());
        this->window.draw(buttonP->getText().getText());
    }
    /* Buttons Actions */
    for (auto buttonA: this->gameInfo->getListButtonAction()) {
        this->window.draw(buttonA->getRectangle());
        this->window.draw(buttonA->getText().getText());
    }
    this->window.display();
}

void Render::debt(int player) {

}

Render::~Render() {
    delete this;
}
