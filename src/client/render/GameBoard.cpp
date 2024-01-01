#include "GameBoard.h"

using namespace std;
using namespace render;

GameBoard::GameBoard(const vector<state::Player>& listPlayer) {
    this->board = *new Board();
    for (state::Player player: listPlayer) {
        this->dictTokenPlayer.emplace(new Token(player.getToken()), player);
    }
    for (auto tokenPlayer: this->dictTokenPlayer) {
        tokenPlayer.first->posUpdate(tokenPlayer.second);
    }
}

sf::Vector2u GameBoard::getSizeBoard() {
    return this->board.getSize();
}

sf::Sprite GameBoard::getSpriteBoard() {
    return this->board.getSprite();
}

void GameBoard::draw(sf::RenderWindow &window) {
    /* Draw board and tokens */
    window.draw(this->getSpriteBoard());
    for (auto tokenPlayer: this->dictTokenPlayer) {
        tokenPlayer.first->draw(window);
    }
}

GameBoard::~GameBoard() {
    delete this;
}
