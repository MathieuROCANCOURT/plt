#include "GameInformation.h"

using namespace std;
using namespace render;

GameInformation::GameInformation(sf::Vector2u sizeBoard, vector<state::Player> listPlayer, const state::Bank &bank)
        : sizeBoard(sizeBoard) {

    vector<std::string> listNameAction = {"Launch Dices", "Buy", "Sell", "Abandon"};
    this->listButtonAction.emplace_back(new Button(140, 40, float(sizeBoard.x) + 10, float(sizeBoard.y) * 0.9,
                                                   listNameAction[0],
                                                   float(sizeBoard.x) + 20, float(sizeBoard.y) * 0.91));
    this->listButtonAction.emplace_back(new Button(50, 40, float(sizeBoard.x) + 160, float(sizeBoard.y) * 0.9,
                                                   listNameAction[1],
                                                   float(sizeBoard.x) + 170, float(sizeBoard.y) * 0.91));
    this->listButtonAction.emplace_back(new Button(50, 40, float(sizeBoard.x) + 220, float(sizeBoard.y) * 0.9,
                                                   listNameAction[2],
                                                   float(sizeBoard.x) + 230, float(sizeBoard.y) * 0.91));

    this->listButtonAction.emplace_back(new Button(90, 40, float(sizeBoard.x) + 280, float(sizeBoard.y) * 0.9,
                                                   listNameAction[3],
                                                   float(sizeBoard.x) + 285, float(sizeBoard.y) * 0.91));

    this->playerInfo = new PlayerInformation(listPlayer, sizeBoard);
    this->bankInfo = new BankInformation(bank, sizeBoard);

}

vector<Button *> GameInformation::getListButtonAction() {
    return this->listButtonAction;
}

const sf::Vector2u &GameInformation::getSizeBoard() const {
    return this->sizeBoard;
}

BankInformation *GameInformation::getBankInformation() {
    return this->bankInfo;
}

PlayerInformation *GameInformation::getPlayerInformation() {
    return this->playerInfo;
}

void GameInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos) {
    static vector<Cases *> listCasesPlayer;
    /* Cases Bank */
    this->bankInfo->draw(window, cursorPos);
    //this->hoverCase(cursorPos, listCasesPlayer, window);

    /* Buttons Actions */
    for (auto buttonA: this->listButtonAction) {
        window.draw(buttonA->getRectangle());
        window.draw(buttonA->getText().getText());
    }

    this->playerInfo->draw(window, cursorPos);
    this->bankInfo->draw(window, cursorPos);
}
