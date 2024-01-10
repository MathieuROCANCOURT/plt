#include "Box.h"
using namespace std;
using namespace state;


Box::Box(int position, bool isProperty, bool isCard, bool money, bool chance, bool goToJail) : position(position), isProperty(isProperty), isCard(isCard), money(money), chance(chance), goToJail(goToJail){
}

bool Box::getIsProperty() {
    return this->isProperty;
}

bool Box::getIsCard() {
    return this->isCard;
}

bool Box::getMoney() {
    return this->money;
}

bool Box::getChance() {
    return this->chance;
}

bool Box::getGoToJail() {
    return this->goToJail;
}
