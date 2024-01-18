#include "Board.h"
#include "config.h"

using namespace render;
using namespace std;

Board::Board() {
    string path = RES_DIR;
    // Charger le fichier du plateau de l'image
    if (!this->textureBoard.loadFromFile(path + "Plateau_monopoly_resize.jpg")) {
        perror("Error load file board.");
    }
    this->spriteBoard.setTexture(this->textureBoard);
}

sf::Sprite Board::getSprite() {
    return this->spriteBoard;
}

sf::Vector2u Board::getSize(){
    return this->textureBoard.getSize();
}

Board::~Board() = default;
