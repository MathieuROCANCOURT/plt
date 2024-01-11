#include "GameInformation.h"
#include <utility>
#include <fstream>
#include <sstream>
#include "config.h"

using namespace std;
using namespace render;

GameInformation::GameInformation(sf::Vector2u sizeBoard, state::State currentState)
        : sizeBoard(sizeBoard), currentState(std::move(currentState)) {
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
    /* Variables to recuperate in csv file */
    string textButton, record;
    float sizeXButton, sizeYButton, posXButton, posYButton, posXText, posYText;

    getline(sstream, record);
    istringstream line(record);
    getline(line, record, '\n'); // Line header

    for (int i = 0; i < 8; i++) {
        getline(sstream, record);
        istringstream line(record);
        getline(line, record, ',');
        sizeXButton = stof(record);
        getline(line, record, ',');
        sizeYButton = stof(record);
        getline(line, record, ',');
        posXButton = float(this->sizeBoard.x) + stof(record);
        getline(line, record, ',');
        posYButton = float(this->sizeBoard.y) * stof(record);
        getline(line, record, ',');
        textButton = record;
        getline(line, record, ',');
        posXText = float(this->sizeBoard.x) + stof(record);
        getline(line, record, ',');
        posYText = float(this->sizeBoard.y) * stof(record);

        if (textButton != "Abandon") {
            this->listButtonAction.push_back(
                    new Button(sizeXButton, sizeYButton, posXButton, posYButton, textButton, posXText, posYText));
        } else {
            this->listButtonAction.push_back(
                    new Button(sizeXButton, sizeYButton, posXButton, posYButton, textButton, posXText, posYText,
                               sf::Color::Red));
        }
    }
    this->listPlayer = this->currentState.getListPlayer();
    this->bank = this->currentState.getBank();

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

void GameInformation::setButtonInteractive() {
    static int startTurnIndex[6] = {0, 2, 3, 4, 5, 6};
    static int endTurnIndex[6] = {1, 2, 3, 4, 5, 6};

    vector<Button *> startTurnButton;
    vector<Button *> endTurnButton;

    for (int index: startTurnIndex) {
        startTurnButton.push_back(this->listButtonAction[index]);
    }
    for (int index: endTurnIndex) {
        endTurnButton.push_back(this->listButtonAction[index]);
    }

    if (this->buttonInteractive->getListButtons().empty() ||
        this->buttonInteractive->getFocus() == this->listButtonAction[1]) {
        this->buttonInteractive->changeListButton(startTurnButton);
    } else if (this->buttonInteractive->getFocus() == this->listButtonAction[0]) {
        this->buttonInteractive->changeListButton(endTurnButton);
    } else if (this->buttonInteractive->getFocus() == this->listButtonAction[6]) {
        this->playerInfo->setListPlayer(this->currentState.getListPlayer());
        this->buttonInteractive->changeListButton(startTurnButton);
    }
}

void GameInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos, sf::Event event) {
    static vector<Cases *> listCasesPlayer;
    /* Cases Bank */
    this->bankInfo->draw(window, cursorPos);

    /* Buttons Actions */
    this->setButtonInteractive();
    this->buttonInteractive->draw(window, cursorPos, event);

    this->playerInfo->draw(window, cursorPos, event);
    this->bankInfo->draw(window, cursorPos);
}

GameInformation::~GameInformation() = default;
