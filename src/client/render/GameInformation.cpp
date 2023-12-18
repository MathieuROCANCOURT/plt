#include <iostream>
#include "GameInformation.h"
#include "state/Player.h"

using namespace std;
using namespace render;

GameInformation::GameInformation(sf::Vector2u size, int nbPlayer) : nbPlayer(nbPlayer), size(size) {
    vector<std::string> listeNamePlayer = {"Player 1", "Player 2", "Player 3", "Player 4", "Player 5", "Player 6"};
    for (int i = 0; i < nbPlayer; i++) {
        this->listButton.emplace_back(95, 40, float(size.x) + float(i) * 110 + 10, 5, listeNamePlayer[i],
                                      float(size.x) + float(i) * 110 + 20, 10);
    }
    vector<std::string> listNameAction = {"Lancer dés", "Acheter", "Vendre", "Abandonner"};
    for (int i = 0; i < 4; i++) {
        this->listButton.emplace_back(95, 40, float(size.x) + float(i) * 110 + 10, float(size.y) * 0.9, listNameAction[i],
                                      float(size.x) + float(i) * 110 + 20, 10);
    }
    this->listText.emplace_back(*new Text("BANQUE", float(size.x) * 1.35, float(size.y) / 3));
}

vector<Button> GameInformation::getListButton() {
    return this->listButton;
}

vector<Text> GameInformation::getListText() {
    cout << this->listText.size() << endl;
    return this->listText;
}

vector<Cases *> GameInformation::CreateCases(int clickwhere, vector<Cases *> listCases, sf::Vector2u size) {
    const sf::Color color[8] = {
            sf::Color(0xFE90C9FF),
            sf::Color::Cyan,
            sf::Color::Magenta,
            sf::Color(0xE79C62FF),
            sf::Color::Red,
            sf::Color::Yellow,
            sf::Color::Green,
            sf::Color::Blue
    };
    listCases.clear();
    /* Create all cases of properties */
    int rep, count = 0;
    float posX_case = float(size.x) * 1.085, posY_case = float(size.y) / 15;
    for (auto c: color) {
        if (count == 4) {
            posY_case += float(size.y) / 12;
            posX_case = float(size.x) * 1.085;
        }
        if (count == 0 || c == sf::Color::Blue) {
            rep = 2;
        } else {
            rep = 3;
        }
        for (int i = 0; i < rep; i++) {
            auto cases = new Cases(posX_case, posY_case, c);
            listCases.push_back(cases);
            posX_case += float(size.x) * 0.072;
        }
        posX_case += float(size.x) * 0.03;
        count++;
    }
    posX_case = float(size.x) * 1.3, posY_case += float(size.y) / 12;
    for (int i = 0; i < 2; ++i) {
        auto cases = new Cases(posX_case, posY_case, sf::Color(0xB8B8B8FF));
        listCases.push_back(cases);
        posX_case += float(size.x) * 0.072;
    }
    posX_case += float(size.x) * 0.1;
    for (int i = 0; i < 4; ++i) {
        auto cases = new Cases(posX_case, posY_case, sf::Color(0x66666FF));
        listCases.push_back(cases);
        posX_case += float(size.x) * 0.072;
    }

    return listCases;
}
