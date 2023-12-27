#include "BankInformation.h"
#include "config.h"

using namespace state;
using namespace render;
using namespace std;

BankInformation::BankInformation(Bank bank, sf::Vector2u sizeBoard){
    string pathname = RES_DIR;
    if (!this->textureApart.loadFromFile(pathname + "iconApart.png")){
        perror("Error load icon apart");
    }
    if (!this->textureHostel.loadFromFile(pathname + "iconHostel.png")){
        perror("Error load icon hostel");
    }
    this->spriteApart.setTexture(this->textureApart);
    this->spriteHostel.setTexture(this->textureHostel);

    this->spriteApart.move(sizeBoard.x * 1.65, sizeBoard.y * 0.39);
    this->spriteHostel.move(sizeBoard.x * 1.8, sizeBoard.y * 0.39);

    this->textBank = *new Text("BANQUE", sizeBoard.x * 1.42, sizeBoard.y * 0.39);
    this->textApart = *new Text(to_string(bank.getNbApartBank()), sizeBoard.x * 1.72, sizeBoard.y * 0.39);
    this->textHostel = *new Text(to_string(bank.getNbHostelBank()), sizeBoard.x * 1.86, sizeBoard.y * 0.39);
}

sf::Sprite BankInformation::getSpriteApart() {
    return this->spriteApart;
}

sf::Sprite BankInformation::getSpriteHostel() {
    return this->spriteHostel;
}

Text BankInformation::getTextBank() {
    return this->textBank;
}

Text BankInformation::getTextApart() {
    return this->textApart;
}

Text BankInformation::getTextHostel() {
    return this->textHostel;
}

void BankInformation::draw(sf::RenderWindow &window) {
    /* Draw texts and sprite house and apart */
    window.draw(this->getSpriteApart());
    window.draw(this->getSpriteHostel());
    window.draw(this->textBank.getText());
    window.draw(this->textApart.getText());
    window.draw(this->textHostel.getText());

}

