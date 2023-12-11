//
// Created by mathieu on 20/10/23.
//
#include "Dices.h"
using namespace std;
using namespace state;

bool Dices::isDouble = false;
int Dices::score = 0;
Dices::Dices(){ }

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


