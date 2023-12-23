#include "GameInformation.h"
#include "config.h"

using namespace std;
using namespace render;

GameInformation::GameInformation(sf::Vector2u size, int nbPlayer) : nbPlayer(nbPlayer), size(size) {
    vector<std::string> listeNamePlayer = {"Player 1", "Player 2", "Player 3", "Player 4", "Player 5", "Player 6"};
    for (int i = 0; i < nbPlayer; i++) {
        this->listButtonPlayer.emplace_back(
                new Button(95, 40, float(size.x) + float(i) * 110 + 10, 5, listeNamePlayer[i],
                           float(size.x) + float(i) * 110 + 20, 10));
    }

    vector<std::string> listNameAction = {"Launch Dices", "Buy", "Sell", "Abandon"};
    this->listButtonAction.emplace_back(new Button(140, 40, float(size.x) + 10, float(size.y) * 0.9,
                                                   listNameAction[0],
                                                   float(size.x) + 20, float(size.y) * 0.91));
    this->listButtonAction.emplace_back(new Button(50, 40, float(size.x) + 160, float(size.y) * 0.9,
                                                   listNameAction[1],
                                                   float(size.x) + 170, float(size.y) * 0.91));
    this->listButtonAction.emplace_back(new Button(50, 40, float(size.x) + 220, float(size.y) * 0.9,
                                                   listNameAction[2],
                                                   float(size.x) + 230, float(size.y) * 0.91));

    this->listButtonAction.emplace_back(new Button(90, 40, float(size.x) + 280, float(size.y) * 0.9,
                                                   listNameAction[3],
                                                   float(size.x) + 285, float(size.y) * 0.91));

    this->listText.emplace_back("BANQUE", float(size.x) * 1.4, float(size.y) * 0.38);
}

vector<Button *> GameInformation::getListButtonPlayer() {
    return this->listButtonPlayer;
}

vector<Button *> GameInformation::getListButtonAction() {
    return this->listButtonAction;
}

vector<Text> GameInformation::getListText() {
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
            posY_case += 50;
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
    posX_case = float(size.x) * 1.3, posY_case += 50;
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

void GameInformation::hoverCase(sf::Vector2i cursorPos, std::vector<Cases *> listCases, sf::RenderWindow & window) {
    int whichCase = 0;
    for (auto * box: listCases) {
        if (box->getSquare().getGlobalBounds().contains(cursorPos.x, cursorPos.y)) {
            sf::Texture textureCard;
            sf::Sprite spriteCard;
            string path = RES_DIR;
            string fileName = path + "Properties/";
            switch (whichCase) {
                case 0:
                    fileName += "Pink/lens";
                    break;
                case 1:
                    fileName += "Pink/bordeaux";
                    break;
                case 2:
                    fileName += "BlueLight/strasbourg";
                    break;
                case 3:
                    fileName += "BlueLight/saint-etienne";
                    break;
                case 4:
                    fileName += "BlueLight/nantes";
                    break;
                case 5:
                    fileName += "Purple/noumea";
                    break;
                case 6:
                    fileName += "Purple/lyon";
                    break;
                case 7:
                    fileName += "Purple/rouen";
                    break;
                case 8:
                    fileName += "Orange/toulouse";
                    break;
                case 9:
                    fileName += "Orange/besançon";
                    break;
                case 10:
                    fileName += "Orange/dijon";
                    break;
                case 11:
                    fileName += "Red/montpellier";
                    break;
                case 12:
                    fileName += "Red/lille";
                    break;
                case 13:
                    fileName += "Red/metz";
                    break;
                case 14:
                    fileName += "Yellow/nimes";
                    break;
                case 15:
                    fileName += "Yellow/nancy";
                    break;
                case 16:
                    fileName += "Yellow/clermont-ferrand";
                    break;
                case 17:
                    fileName += "Green/annecy";
                    break;
                case 18:
                    fileName += "Green/caen";
                    break;
                case 19:
                    fileName += "Green/perpignan";
                    break;
                case 20:
                    fileName += "Blue/reims";
                    break;
                case 21:
                    fileName += "Blue/dunkerque";
                    break;
                case 22:
                    fileName += "PublicService/télécoms";
                    break;
                case 23:
                    fileName += "PublicService/satellite";
                    break;
                case 24:
                    fileName += "Station/station_europe";
                    break;
                case 25:
                    fileName += "Station/station_saint-charles";
                    break;
                case 26:
                    fileName += "Station/station_montparnasse";
                    break;
                case 27:
                    fileName += "Station/station_part-dieu";
                    break;
                default:
                    perror("Number error Case.");
            }
            if (!textureCard.loadFromFile(fileName + ".png")) {
                perror("Error load file card property.\n");
            }
            spriteCard.setTexture(textureCard);
            spriteCard.move(float(this->size.x) / 3, float(this->size.y) / 4);
            window.draw(spriteCard);
            break;
        }
        whichCase++;
    }
}
