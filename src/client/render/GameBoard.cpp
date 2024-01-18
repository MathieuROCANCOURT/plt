#include "GameBoard.h"
#include <utility>

using namespace std;
using namespace render;

GameBoard::GameBoard(vector<state::Player> listPlayer) : listPlayer(std::move(listPlayer)) {
    this->board = new Board();
    for (state::Player player: this->listPlayer) {
        this->dictTokenPlayer.emplace(new Token(player.getToken()), player);
    }
    this->updatePos(); //Work here
}

sf::Vector2u GameBoard::getSizeBoard() {
    return this->board->getSize();
}

sf::Sprite GameBoard::getSpriteBoard() {
    return this->board->getSprite();
}

void GameBoard::updatePos() {
    for (auto tokenPlayer: this->dictTokenPlayer) {
        tokenPlayer.first->posUpdate(tokenPlayer.second);
    }
}

void GameBoard::draw(sf::RenderWindow &window) {
    /* Draw board and tokens */
    window.draw(this->getSpriteBoard());
    for (auto tokenPlayer: this->dictTokenPlayer) {
        tokenPlayer.first->draw(window);
    }
}

GameBoard::~GameBoard() = default;
