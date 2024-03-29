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
    this->setButtonInteractive();
    this->listPlayer = this->currentState.getListPlayer();
    this->bank = this->currentState.getBank();

    this->playerInfo = new PlayerInformation(this->listPlayer, this->sizeBoard);
    this->bankInfo = new BankInformation(this->bank, this->sizeBoard);

    this->textInformation = new Text("Turn of " + this->currentState.getCurrentPlayer().getName() + ".",
                                     float(this->sizeBoard.x * 1.2),
                                     float(this->sizeBoard.y * 0.75),
                                     20);
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

    vector<Button *> TurnButton;

    if (this->buttonInteractive->getFocus() == this->listButtonAction[0]) {
        this->listButtonAction[0]->deselect();
        for (int index: endTurnIndex) {
            TurnButton.push_back(this->listButtonAction[index]);
        }
        this->buttonInteractive->changeListButton(TurnButton);
        this->textInformation->setStringText("Tu as obtenu " + to_string(this->currentState.getScoreDices()) + ", Double:" +
                                                     to_string(this->currentState.getIsDouble()) + ", Nombre de double:" +
                                                     to_string(this->currentState.getNbDouble()));
    } else if (this->buttonInteractive->getListButtons().empty()) {
        this->listButtonAction[1]->deselect();
        for (int index: startTurnIndex) {
            TurnButton.push_back(this->listButtonAction[index]);
        }
        this->buttonInteractive->changeListButton(TurnButton);
    } else if (this->buttonInteractive->getFocus() == this->listButtonAction[1]){
        this->listButtonAction[1]->deselect();
        for (int index: startTurnIndex) {
            TurnButton.push_back(this->listButtonAction[index]);
        }
        this->buttonInteractive->changeListButton(TurnButton);
        this->textInformation->setStringText("Fin du tour de " + this->currentState.getCurrentPlayer().getName() + ".");
    } else if (this->buttonInteractive->getFocus() == this->listButtonAction[6]) {
        this->listButtonAction[6]->deselect();
        this->playerInfo->setListPlayer(this->currentState.getListPlayer());
        for (int index: startTurnIndex) {
            TurnButton.push_back(this->listButtonAction[index]);
        }
        this->buttonInteractive->changeListButton(TurnButton);
        this->textInformation->setStringText("Abandon de " + this->currentState.getCurrentPlayer().getName() + ".");
    }
}

void GameInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos, sf::Event event) {
    static vector<Cases *> listCasesPlayer;
    /* Cases Bank */
    this->bankInfo->draw(window, cursorPos);

    /* Buttons Actions */
    this->buttonInteractive->draw(window, cursorPos, event);

    if (event.type == sf::Event::MouseButtonReleased) {
        this->setButtonInteractive();
    }

    this->playerInfo->draw(window, cursorPos, event);
    this->bankInfo->draw(window, cursorPos);
    this->textInformation->draw(window);
}

GameInformation::~GameInformation() = default;
