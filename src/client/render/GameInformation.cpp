#include "GameInformation.h"

using namespace std;
using namespace render;

GameInformation::GameInformation(sf::Vector2u sizeBoard, vector<state::Player> listPlayer, const state::Bank &bank)
        : sizeBoard(sizeBoard) {
    vector<std::string> listNameAction = {"Launch Dices", "Buy", "Sell", "Abandon"};

    vector<Button *> listButtonActionInit;
    vector<Button *> listButtonEndTurn;

    listButtonActionInit.emplace_back(new Button(140, 40, float(sizeBoard.x) + 10, float(sizeBoard.y) * 0.9,
                                                 listNameAction[0], float(sizeBoard.x) + 20,
                                                 float(sizeBoard.y) * 0.91));
    listButtonActionInit.emplace_back(new Button(50, 40, float(sizeBoard.x) + 160, float(sizeBoard.y) * 0.9,
                                                 listNameAction[1], float(sizeBoard.x) + 170,
                                                 float(sizeBoard.y) * 0.91));
    listButtonActionInit.emplace_back(new Button(50, 40, float(sizeBoard.x) + 220, float(sizeBoard.y) * 0.9,
                                                 listNameAction[2], float(sizeBoard.x) + 230,
                                                 float(sizeBoard.y) * 0.91));
    listButtonActionInit.emplace_back(new Button(90, 40, float(sizeBoard.x) + 510, float(sizeBoard.y) * 0.9,
                                                 listNameAction[3], float(sizeBoard.x) + 515, float(sizeBoard.y) * 0.91,
                                                 sf::Color::Red));

    this->listButtonAction.push_back(new AllButtons(listButtonActionInit));

    this->playerInfo = new PlayerInformation(listPlayer, sizeBoard);
    this->bankInfo = new BankInformation(bank, sizeBoard);

}

vector<AllButtons *> GameInformation::getListButtonAction() {
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

void GameInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos, sf::Event event) {
    static vector<Cases *> listCasesPlayer;
    /* Cases Bank */
    this->bankInfo->draw(window, cursorPos);
    //this->hoverCase(cursorPos, listCasesPlayer, window);

    /* Buttons Actions */
    for (auto listButton: this->listButtonAction) {
        listButton->setFocus(cursorPos, event);
        listButton->draw(window);
    }

    this->playerInfo->draw(window, cursorPos, event);
    this->bankInfo->draw(window, cursorPos);
}
