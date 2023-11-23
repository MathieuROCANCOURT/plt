#include "Player.h"

using namespace std;
using namespace state;


void Player::setPosition(int) {
    this->position = position;
}

int Player::getPosition() {
    return this->position;
}

void Player::setMoney(long long int) {
    this->money = money;
}

long long Player::getMoney() {
    return this->money;
}

void Player::addToPlayerProperties(Property property) {
    this->playerProperties.push_back(property);
}

std::vector<Property> Player::getPlayerProperties() {
    return this->playerProperties;
}

GameStatus Player::getGameStatus() {
    return this->gameStatus;
}

void Player::setGameStatus(GameStatus gameStatus) {
    this->gameStatus = gameStatus;
}

void Player::eraseFromPlayerProperties(std::vector<Property>::iterator indice) {
    this->playerProperties.erase(indice);
}

std::string Player::getName() {
    return this->name;
}

bool Player::operator==(const Player &other) const {
    return (this->name == other.name);
}


