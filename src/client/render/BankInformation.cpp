#include "BankInformation.h"
#include "config.h"
#include <utility>

using namespace state;
using namespace render;
using namespace std;

BankInformation::BankInformation(Bank bank, sf::Vector2u sizeBoard): bank(std::move(bank)) {
    sf::Texture textureApart, textureHostel;
    string pathname = RES_DIR;
    if (!textureApart.loadFromFile(pathname + "iconApart.png")){
        perror("Error load icon apart");
    }
    if (!textureHostel.loadFromFile(pathname + "iconHostel.png")){
        perror("Error load icon hostel");
    }
    this->spriteApart.setTexture(textureApart);
    this->spriteHostel.setTexture(textureHostel);

    this->spriteApart.move(sf::Vector2f(sizeBoard) + sf::Vector2f(600, 600));
}


