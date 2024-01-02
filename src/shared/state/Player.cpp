#include <iostream>
#include "Player.h"

using namespace std;
using namespace state;

Player::Player(std::string name, Token token) : name(name), money(15000000), debt(NOT_DEBT), position(1), freeJailCard(0), nbTotalAppart(0), nbTotalHostel(0), gameStatus(PLAYINGFREE), nbTurnInJail(0), token(token){

}


void Player::setPosition(int pos) {
    this->position = pos;
}

int Player::getPosition() {
    return this->position;
}

void Player::setMoney(long long mon) {
    this->money = mon;
}

long long Player::getMoney() {
    return this->money;
}

void Player::addToPlayerProperties(Property property) {
    this->playerProperties.push_back(property);
}

Token Player::getToken() {
    return this->token;
}

std::vector<Property> Player::getPlayerProperties() {
    return this->playerProperties;
}

GameStatus Player::getGameStatus() {
    return this->gameStatus;
}

void Player::setGameStatus(GameStatus changeGameStatus) {
    this->gameStatus = changeGameStatus;
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

int Player::getFreeJailCard() {
    return this->freeJailCard;
}

void Player::setFreeJailCard(int NbFreeJailCard) {

    this->freeJailCard = NbFreeJailCard;

}

void Player::setDebt(Debt deb) {
    this->debt = deb;
}

void Player::setNbTurnInJail(int turnInJail) {
    this->nbTurnInJail = turnInJail;
}

int Player::getNbTurnInJail() {
    return this->nbTurnInJail;
}

Debt Player::getDebt() {
    return this->debt;
}

int Player::getNbdouble() {
    return this->NbDouble;
}
