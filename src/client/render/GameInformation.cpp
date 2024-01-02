#include "GameInformation.h"
#include <utility>

using namespace std;
using namespace render;

GameInformation::GameInformation(sf::Vector2u sizeBoard, vector<state::Player> listPlayer, state::Bank bank)
        : sizeBoard(sizeBoard), listPlayer(std::move(listPlayer)), bank(std::move(bank)) {
    vector<std::string> listNameAction = {"Launch Dices", "Buy", "Sell", "Abandon"};

    vector<Button *> listButtonActionInit;
    vector<Button *> listButtonEndTurn;

    listButtonActionInit.emplace_back(new Button(140, 40, float(this->sizeBoard.x) + 10, float(this->sizeBoard.y * 0.9),
                                                 listNameAction[0], float(this->sizeBoard.x) + 20,
                                                 float(this->sizeBoard.y * 0.91)));
    listButtonActionInit.emplace_back(new Button(50, 40, float(this->sizeBoard.x) + 160, float(this->sizeBoard.y * 0.9),
                                                 listNameAction[1], float(this->sizeBoard.x) + 170,
                                                 float(this->sizeBoard.y * 0.91)));
    listButtonActionInit.emplace_back(new Button(50, 40, float(this->sizeBoard.x) + 220, float(this->sizeBoard.y * 0.9),
                                                 listNameAction[2], float(this->sizeBoard.x) + 230,
                                                 float(this->sizeBoard.y * 0.91)));
    listButtonActionInit.emplace_back(new Button(90, 40, float(this->sizeBoard.x) + 510, float(this->sizeBoard.y * 0.9),
                                                 listNameAction[3], float(this->sizeBoard.x) + 515,
                                                 float(this->sizeBoard.y * 0.91), sf::Color::Red));

    this->listButtonAction.push_back(new AllButtons(listButtonActionInit));

    this->playerInfo = new PlayerInformation(this->listPlayer, this->sizeBoard);
    this->bankInfo = new BankInformation(this->bank, this->sizeBoard);

}

void GameInformation::setBankInformation(state::Bank actBank) {
    this->bank = std::move(actBank);
}

void GameInformation::setPlayerInformation(vector<state::Player> modifyListPlayer) {
    this->listPlayer = std::move(modifyListPlayer);
}

void GameInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos, sf::Event event) {
    static vector<Cases *> listCasesPlayer;
    /* Cases Bank */
    this->bankInfo->draw(window, cursorPos);

    /* Buttons Actions */
    for (auto listButton: this->listButtonAction) {
        listButton->draw(window, cursorPos, event);
    }

    this->playerInfo->draw(window, cursorPos, event);
    this->bankInfo->draw(window, cursorPos);
}
