#include <iostream>
#include "Board.h"

using namespace render;
using namespace std;

Board::Board() {
    // Charger le fichier du plateau de l'image
    if (!this->textureBoard.loadFromFile("./../res/Plateau_monopoly_resize.jpg")) {
        cout << "Error load file board." << endl;
    }
    this->spriteBoard.setTexture(this->textureBoard);
}

sf::Sprite Board::getSprite() {
    return this->spriteBoard;
}

sf::Vector2u Board::getSize(){
    return this->textureBoard.getSize();
}

Board::~Board() {
    delete this;
}
