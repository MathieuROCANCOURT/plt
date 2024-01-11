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

void Player::setMoney(long long) {
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

Token Player::getToken(){
    return this->token;
}

bool Player::operator==(const Player &other) const {
    return (this->IdPlayerTour == other.IdPlayerTour);
}
bool Player::operator!=(const Player &other) const {
    return (this->IdPlayerTour != other.IdPlayerTour);
}
int Player::getFreeJailCard() {
    return this->freeJailCard;
}

void Player::setFreeJailCard(int NbFreeJailCard) {

    this->freeJailCard = NbFreeJailCard;

}

void Player::setDebt(Debt debt) {
    this->debt = debt;
}

void Player::setNbTurnInJail(int nbTurnInJail) {
    this->nbTurnInJail = nbTurnInJail;
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

Playing Player::getIdPlayerTour() {
    return this->IdPlayerTour;
}

void Player::setIdPlayerTour(Playing idPlayer) {
    this->IdPlayerTour=idPlayer;
}

void Player::setNbTotalHostel(int NbTotalHostel) {
    this->nbTotalHostel=NbTotalHostel;
}

void Player::setNbTotalApart(int NbTotalApart) {
    this->nbTotalAppart=NbTotalApart;
}

int Player::getNbTotalHostel() {
    return this->nbTotalHostel;
}

int Player::getNbTotalApart() {
    return this->nbTotalAppart;
}






