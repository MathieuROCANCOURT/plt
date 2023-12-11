#include "GameBoard.h"

using namespace std;
using namespace render;

GameBoard::GameBoard(int nbPlayer): nbPlayer(nbPlayer) {
    this->board = *new Board();
    for (int i = 0; i < this->nbPlayer; i++){
        this->list_token.push_back(new Token());
    }
}

sf::Vector2u GameBoard::getSizeBoard() {
    return this->board.getSize();
}

sf::Sprite GameBoard::getSpriteBoard() {
    return this->board.getSprite();
}

GameBoard::~GameBoard() {
    delete this;
}
