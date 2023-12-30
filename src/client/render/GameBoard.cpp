#include "GameBoard.h"

using namespace std;
using namespace render;

GameBoard::GameBoard(int nbPlayer): nbPlayer(nbPlayer) {
    this->board = *new Board();
    for (int i = 0; i < this->nbPlayer; i++){
        this->list_token.emplace_back(new Token(i));
    }
    float xmove, ymove = 35;
    for (int i = 0; i <= (int) this->nbPlayer / 2; i++){
        xmove = 80;
        for (int j = 0; j < 2; j++){
            if (i * 2 + j < this->nbPlayer) {
                this->list_token[i * 2 + j]->posMove(sf::Vector2f(this->board.getSize()) - sf::Vector2f(xmove, ymove));
                xmove = 35;
            }
        }
        ymove += 25;
    }
}

sf::Vector2u GameBoard::getSizeBoard() {
    return this->board.getSize();
}

sf::Sprite GameBoard::getSpriteBoard() {
    return this->board.getSprite();
}

std::vector<Token *> GameBoard::getListToken() {
    return this->list_token;
}

void GameBoard::draw(sf::RenderWindow &window) {
    /* Draw board and tokens */
    window.draw(this->getSpriteBoard());
    for (auto token: this->list_token) {
        token->draw(window);
    }
}

GameBoard::~GameBoard() {
    delete this;
}
