#include "Dices.h"

using namespace state;

bool Dices::isDouble = false;
int Dices::score = 0;
Dices::Dices(){ }

void Dices::setIsDouble(bool isDouble) {
    this->isDouble = isDouble;
}

void Dices::setScore(int sc) {
    this->score = sc;
}

int Dices::getScore() {
    return this->score;
}

bool Dices::getIsDouble() {
    return this->isDouble;
}


