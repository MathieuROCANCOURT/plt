#include "GameInformation.h"
#include "config.h"

using namespace std;
using namespace render;

GameInformation::GameInformation(sf::Vector2u sizeBoard, int nbApart, int nbHostel, int nbPlayer) : nbPlayer(nbPlayer),
                                                                                                    nbApart(nbApart),
                                                                                                    nbHostel(nbHostel),
                                                                                                    sizeBoard(
                                                                                                            sizeBoard) {
    string pathname = RES_DIR;

    vector<std::string> listeNamePlayer = {"Player 1", "Player 2", "Player 3", "Player 4", "Player 5", "Player 6"};
    for (int i = 0; i < nbPlayer; i++) {
        this->listButtonPlayer.emplace_back(
                new Button(95, 40, float(sizeBoard.x) + float(i) * 110 + 10, 5, listeNamePlayer[i],
                           float(sizeBoard.x) + float(i) * 110 + 20, 10));
    }

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
    this->listText.emplace_back(*new Text("BANQUE", float(sizeBoard.x) * 1.42, float(sizeBoard.y) * 0.39));
    this->listText.emplace_back(*new Text(to_string(this->nbApart), float(sizeBoard.x) * 1.72, float(sizeBoard.y) * 0.39));
    this->listText.emplace_back(*new Text(to_string(this->nbHostel), float(sizeBoard.x) * 1.86, float(sizeBoard.y) * 0.39));

    if (!this->apartTexture.loadFromFile(pathname + "iconApart.png")) {
        perror("Error load file icon apart");
    }
    if (!this->hostelTexture.loadFromFile(pathname + "iconHostel.png")) {
        perror("Error load file icon hostel");
    }
    this->spriteApart.setTexture(this->apartTexture);
    this->spriteHostel.setTexture(this->hostelTexture);
    this->spriteApart.move(this->sizeBoard.x * 1.65, this->sizeBoard.y * 0.39);
    this->spriteHostel.move(this->sizeBoard.x * 1.8, this->sizeBoard.y * 0.39);
}

const sf::Vector2u &GameInformation::getSizeBoard() const {
    return this->sizeBoard;
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

sf::Sprite GameInformation::getSpriteApart() const {
    return this->spriteApart;
}

sf::Sprite GameInformation::getSpriteHostel() const {
    return this->spriteHostel;
}

vector<Cases *> GameInformation::CreateCases(vector<Cases *> listCases, uint yMove) {
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
    float posX_case = float(this->getSizeBoard().x) * 1.12, posY_case = float(yMove);
    for (auto c: color) {
        if (count == 4) {
            posY_case += 50;
            posX_case = float(this->getSizeBoard().x) * 1.12;
        }
        if (count == 0 || c == sf::Color::Blue) {
            rep = 2;
        } else {
            rep = 3;
        }
        for (int i = 0; i < rep; i++) {
            auto cases = new Cases(posX_case, posY_case, c);
            listCases.push_back(cases);
            posX_case += float(this->getSizeBoard().x) * 0.072;
        }
        posX_case += float(this->getSizeBoard().x) * 0.03;
        count++;
    }
    posX_case = float(this->getSizeBoard().x) * 1.3, posY_case += 50;
    for (int i = 0; i < 2; ++i) {
        auto cases = new Cases(posX_case, posY_case, sf::Color(0xB8B8B8FF));
        listCases.push_back(cases);
        posX_case += float(this->getSizeBoard().x) * 0.072;
    }
    posX_case += float(this->getSizeBoard().x) * 0.1;
    for (int i = 0; i < 4; ++i) {
        auto cases = new Cases(posX_case, posY_case, sf::Color(0x66666FF));
        listCases.push_back(cases);
        posX_case += float(this->getSizeBoard().x) * 0.072;
    }

    return listCases;
}

void GameInformation::hoverCase(sf::Vector2i cursorPos, const std::vector<Cases *> &listCases,
                                sf::RenderWindow &window) const {
    int whichCase = 0;
    for (auto *box: listCases) {
        if (box->getSquare().getGlobalBounds().contains(float(cursorPos.x), float(cursorPos.y))) {
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
            spriteCard.move(float(this->getSizeBoard().x) / 3, float(this->getSizeBoard().y) / 4);
            window.draw(spriteCard);
            break;
        }
        whichCase++;
    }
}

