#include "Cases.h"
#include "config.h"

using namespace std;
using namespace render;

Cases::Cases(float posX, float posY, sf::Color caseColor, float radius, int pointCount, sf::Color fillColor,
             float thickness, float rotate) : posX(posX),
                                              posY(posY),
                                              caseColor(caseColor),
                                              radius(radius),
                                              pointCount(pointCount),
                                              fillColor(fillColor),
                                              thickness(thickness),
                                              rotate(rotate) {
    this->square = sf::CircleShape(this->radius, this->pointCount);
    this->square.setFillColor(this->fillColor);
    this->square.setOutlineColor(this->caseColor);
    this->square.setOutlineThickness(this->thickness);
    this->square.move(this->posX, this->posY);
    this->square.rotate(this->rotate);
}

sf::CircleShape Cases::getSquare() {
    return this->square;
}

void Cases::setFillColor(sf::Color changeColor) {
    this->square.setFillColor(changeColor);
}

void Cases::hover(const sf::Vector2i &cursorPos, int whichCase) {
    if (this->square.getGlobalBounds().contains(static_cast<sf::Vector2f>(cursorPos))) {
        string path = RES_DIR;
        string fileName = path + "Properties/";
        sf::Color test = this->square.getOutlineColor();
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
        sf::Texture textureCard;
        sf::Sprite spriteCard;
        if (!textureCard.loadFromFile(fileName + "jpg")) {
            perror("Error load file card property.\n");
        }
        spriteCard.setTexture(textureCard);
    }
}

Cases::~Cases() {
    delete this;
}
