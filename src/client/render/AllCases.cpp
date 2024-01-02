#include "AllCases.h"
#include "config.h"

using namespace std;
using namespace render;

AllCases::AllCases(sf::Vector2u sizeBoard, uint yMove) : sizeBoard(sizeBoard) {
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
            posY_case += 50, posX_case = float(this->sizeBoard.x * 1.12); // New line
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
            posX_case += float(sizeBoard.x * 0.072);
        }
        posX_case += float(sizeBoard.x * 0.03);
    }
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

void render::AllCases::draw(sf::RenderWindow &window, sf::Vector2i cursorPos) {
    for (auto box: this->listCases) {
        box->draw(window);
    }
    this->hover(window, cursorPos);
}

render::AllCases::~AllCases() {
    this->listCases.clear();
    delete this;
}

