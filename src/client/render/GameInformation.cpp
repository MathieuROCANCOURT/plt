#include "GameInformation.h"
#include <utility>
#include <fstream>
#include <sstream>
#include "config.h"

using namespace std;
using namespace render;

GameInformation::GameInformation(sf::Vector2u sizeBoard, vector<state::Player> listPlayer, state::Bank bank)
        : sizeBoard(sizeBoard), listPlayer(std::move(listPlayer)), bank(std::move(bank)) {
    string path = RES_DIR;
    /* Lire fichier ButtonAction.csv*/
    auto fileContent = ostringstream{};
    ifstream input_file(path + "CSV/ButtonAction.csv");
    if (!input_file.is_open()) {
        perror("Could not open the file");
        exit(EXIT_FAILURE);
    }
    fileContent << input_file.rdbuf();
    istringstream sstream(fileContent.str());
    std::vector<string> items;

    vector<string> listStartAction = {"Roll dices", "Buy appart", "Sell apart", "Abandon"};
    vector<string> listStartJail = {"Roll dices", "Free jail", "Abandon"};
    vector<string> listActionBuyAppart = {"Buy", "No buy"};
    vector<string> listEndAction = {"End turn", "Buy appart", "Abandon"};
    vector<string> listDebt = {"Sell", "Abandon"};

    vector<Button *> listButtonActionInit;
    vector<Button *> listButtonInJail;
    vector<Button *> listButtonBuyAppart;
    vector<Button *> listButtonEndTurn;

    listButtonActionInit.emplace_back(new Button(105, 40, float(this->sizeBoard.x) + 10, float(this->sizeBoard.y * 0.9),
                                                 listStartAction[0], float(this->sizeBoard.x) + 20,
                                                 float(this->sizeBoard.y * 0.91)));
    listButtonActionInit.emplace_back(new Button(120, 40, float(this->sizeBoard.x) + 125, float(this->sizeBoard.y * 0.9),
                                                 listStartAction[1], float(this->sizeBoard.x) + 135,
                                                 float(this->sizeBoard.y * 0.91)));
    listButtonActionInit.emplace_back(new Button(105, 40, float(this->sizeBoard.x) + 255, float(this->sizeBoard.y * 0.9),
                                                 listStartAction[2], float(this->sizeBoard.x) + 265,
                                                 float(this->sizeBoard.y * 0.91)));
    listButtonActionInit.emplace_back(new Button(90, 40, float(this->sizeBoard.x) + 565, float(this->sizeBoard.y * 0.9),
                                                 listStartAction[3], float(this->sizeBoard.x) + 570,
                                                 float(this->sizeBoard.y * 0.91), sf::Color::Red));

    this->listButtonAction.push_back(new AllButtons(listButtonActionInit));

    this->playerInfo = new PlayerInformation(this->listPlayer, this->sizeBoard);
    this->bankInfo = new BankInformation(this->bank, this->sizeBoard);

}

std::vector<state::Player> GameInformation::getPlayerInformation() {
    return this->listPlayer;
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

GameInformation::~GameInformation() = default;
