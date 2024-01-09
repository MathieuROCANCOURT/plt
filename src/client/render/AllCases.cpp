#include "AllCases.h"
#include "config.h"

using namespace std;
using namespace render;

AllCases::AllCases(sf::Vector2u sizeBoard, vector<state::Property *> listProperty, uint yMove) : sizeBoard(sizeBoard),
                                                                                                 listProperty(
                                                                                                         std::move(
                                                                                                                 listProperty)) {
    const sf::Color color[10] = {
            sf::Color(0xFE90C9FF),
            sf::Color::Cyan,
            sf::Color::Magenta,
            sf::Color(0xE79C62FF),
            sf::Color::Red,
            sf::Color::Yellow,
            sf::Color::Green,
            sf::Color::Blue,
            sf::Color(0xB8B8B8FF),
            sf::Color(0x66666FF)
    };
    int rep = 0;
    float posX_case, posY_case = float(yMove);
    posX_case = float(this->sizeBoard.x * 1.12);
    for (auto c: color) {
        if (c == sf::Color::Red) {
            posX_case = float(this->sizeBoard.x * 1.12), posY_case += 50; // New line
        }
        if (c == sf::Color(0xFE90C9FF) || c == sf::Color::Blue) {
            rep = 2; // Number of case
        } else if (c == sf::Color(0xB8B8B8FF)) {
            posX_case = float(this->sizeBoard.x * 1.3), posY_case += 50; // New line
        } else if (c == sf::Color(0x66666FF)) {
            posX_case += float(this->sizeBoard.x * 0.1); // Set big space
            rep = 4;
        } else {
            rep = 3;
        }
        for (int i = 0; i < rep; i++) {
            auto cases = new Cases(posX_case, posY_case, c);
            listCases.push_back(cases);
            posX_case += float(this->sizeBoard.x * 0.072);
        }
        posX_case += float(this->sizeBoard.x * 0.03);
    }
}

std::vector<Cases *> AllCases::getListCases() {
    return this->listCases;
}

void render::AllCases::hover(sf::RenderWindow &window, sf::Vector2i cursorPos) {
    int whichCase = 0;
    for (auto *box: this->listCases) {
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
            spriteCard.move(float(this->sizeBoard.x) / 3, float(this->sizeBoard.y) / 4);
            window.draw(spriteCard);
            break;
        }
        whichCase++;
    }
}

void AllCases::updateCases() {
    for (auto cases: this->listCases) {
        cases->setFillColor(sf::Color::White);
    }
    for (auto property: this->listProperty) {
        switch (property->getPosition()) {
            case 2:
                this->listCases[0]->setFillColor(this->listCases[0]->getSquare().getOutlineColor());
                break;
            case 4:
                this->listCases[1]->setFillColor(this->listCases[1]->getSquare().getOutlineColor());
                break;
            case 7:
                this->listCases[2]->setFillColor(this->listCases[2]->getSquare().getOutlineColor());
                break;
            case 9:
                this->listCases[3]->setFillColor(this->listCases[3]->getSquare().getOutlineColor());
                break;
            case 10:
                this->listCases[4]->setFillColor(this->listCases[4]->getSquare().getOutlineColor());
                break;
            case 12:
                this->listCases[5]->setFillColor(this->listCases[5]->getSquare().getOutlineColor());
                break;
            case 14:
                this->listCases[6]->setFillColor(this->listCases[6]->getSquare().getOutlineColor());
                break;
            case 15:
                this->listCases[7]->setFillColor(this->listCases[7]->getSquare().getOutlineColor());
                break;
            case 17:
                this->listCases[8]->setFillColor(this->listCases[8]->getSquare().getOutlineColor());
                break;
            case 19:
                this->listCases[9]->setFillColor(this->listCases[9]->getSquare().getOutlineColor());
                break;
            case 20:
                this->listCases[10]->setFillColor(this->listCases[10]->getSquare().getOutlineColor());
                break;
            case 22:
                this->listCases[11]->setFillColor(this->listCases[11]->getSquare().getOutlineColor());
                break;
            case 24:
                this->listCases[12]->setFillColor(this->listCases[12]->getSquare().getOutlineColor());
                break;
            case 25:
                this->listCases[13]->setFillColor(this->listCases[13]->getSquare().getOutlineColor());
                break;
            case 27:
                this->listCases[14]->setFillColor(this->listCases[14]->getSquare().getOutlineColor());
                break;
            case 28:
                this->listCases[15]->setFillColor(this->listCases[15]->getSquare().getOutlineColor());
                break;
            case 30:
                this->listCases[16]->setFillColor(this->listCases[16]->getSquare().getOutlineColor());
                break;
            case 32:
                this->listCases[17]->setFillColor(this->listCases[17]->getSquare().getOutlineColor());
                break;
            case 33:
                this->listCases[18]->setFillColor(this->listCases[18]->getSquare().getOutlineColor());
                break;
            case 35:
                this->listCases[19]->setFillColor(this->listCases[19]->getSquare().getOutlineColor());
                break;
            case 38:
                this->listCases[20]->setFillColor(this->listCases[20]->getSquare().getOutlineColor());
                break;
            case 40:
                this->listCases[21]->setFillColor(this->listCases[21]->getSquare().getOutlineColor());
                break;

                /* Cases publics services */
            case 13:
                this->listCases[22]->setFillColor(this->listCases[22]->getSquare().getOutlineColor());
                break;
            case 29:
                this->listCases[23]->setFillColor(this->listCases[23]->getSquare().getOutlineColor());
                break;

                /* Cases stations */
            case 6:
                this->listCases[24]->setFillColor(this->listCases[24]->getSquare().getOutlineColor());
                break;
            case 16:
                this->listCases[25]->setFillColor(this->listCases[25]->getSquare().getOutlineColor());
                break;
            case 26:
                this->listCases[26]->setFillColor(this->listCases[26]->getSquare().getOutlineColor());
                break;
            case 36:
                this->listCases[27]->setFillColor(this->listCases[27]->getSquare().getOutlineColor());
                break;

            default:
                perror("Error fill color case.");
                break;
        }

    }
}

void render::AllCases::draw(sf::RenderWindow &window, sf::Vector2i cursorPos) {
    this->updateCases();
    for (auto box: this->listCases) {
        box->draw(window);
    }
    this->hover(window, cursorPos);
}

render::AllCases::~AllCases() {
    this->listCases.clear();
    this->listProperty.clear();
    delete this;
}
