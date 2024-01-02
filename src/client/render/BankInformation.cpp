#include "BankInformation.h"
#include "config.h"

using namespace state;
using namespace render;
using namespace std;

BankInformation::BankInformation(Bank bank, sf::Vector2u sizeBoard) : bank(bank){
    string pathname = RES_DIR;
    if (!this->textureApart.loadFromFile(pathname + "iconApart.png")) {
        perror("Error load icon apart");
    }
    if (!this->textureHostel.loadFromFile(pathname + "iconHostel.png")) {
        perror("Error load icon hostel");
    }
    this->spriteApart.setTexture(this->textureApart);
    this->spriteHostel.setTexture(this->textureHostel);

    this->spriteApart.move(float(sizeBoard.x * 1.65), float(sizeBoard.y * 0.39));
    this->spriteHostel.move(float(sizeBoard.x * 1.8), float(sizeBoard.y * 0.39));

    this->textBank = *new Text("BANQUE", float(sizeBoard.x * 1.42), float(sizeBoard.y * 0.39));
    this->textApart = *new Text(to_string(bank.getNbApartBank()), float(sizeBoard.x * 1.72), float(sizeBoard.y * 0.39));
    this->textHostel = *new Text(to_string(bank.getNbHostelBank()), float(sizeBoard.x * 1.86),
                                 float(sizeBoard.y * 0.39));

    this->listCases = new AllCases(sizeBoard, uint(sizeBoard.y * 0.47));
}

sf::Sprite BankInformation::getSpriteApart() {
    return this->spriteApart;
}

sf::Sprite BankInformation::getSpriteHostel() {
    return this->spriteHostel;
}

void BankInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos) {
    /* Draw texts and sprite house and apart */
    window.draw(this->getSpriteApart());
    window.draw(this->getSpriteHostel());
    window.draw(this->textBank.getText());
    window.draw(this->textApart.getText());
    window.draw(this->textHostel.getText());
    this->listCases->draw(window, cursorPos);
}
