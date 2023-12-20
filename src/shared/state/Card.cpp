#include "Card.h"

using namespace std;
using namespace state;


Card::Card(std::string text, bool freeJail, bool money, bool fctHostel, bool moveForwardTo, bool fromOthers, bool jail,
           int *args) : text(text), freeJail(freeJail), money(money), fctHostel(fctHostel), moveForwardTo(moveForwardTo), fromOthers(fromOthers), jail(jail) {
    int index = 0;
    while(args != nullptr){
        this->args[index] = *args;
        index++;
        args = args + 1;
    }

}

std::string Card::getText() {
    return this->text;
}

bool Card::getFreeJail() {
    return this->freeJail;
}

bool Card::getMoney() {
    return this->money;
}

bool Card::getFctHostel() {
    return this->fctHostel;
}

bool Card::getMoveForward() {
    return this->moveForwardTo;
}

bool Card::getFromOthers() {
    return this->fromOthers;
}

bool Card::getJail() {
    return this->jail;
}

std::vector<int> Card::getArgs() {
    return this->args;
}





