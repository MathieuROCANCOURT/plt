//
// Created by mathieu on 20/10/23.
//
#include "Dices.h"
using namespace std;
using namespace state;


Dices::Dices() : isDouble(false), score(0){ }

void Dices::setIsDouble(bool isDouble) {
    this->isDouble = isDouble;
}

void Dices::setScore(int) {
    this->score = score;
}

int Dices::getScore() {
    return this->score;
}

bool Dices::getIsDouble() {
    return this->isDouble;
}


