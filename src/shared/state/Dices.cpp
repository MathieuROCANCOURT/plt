#include "Dices.h"
using namespace std;
using namespace state;


Dices::Dices() : isDouble(false), score(0){ }

void Dices::setIsDouble(bool isdouble) {
    this->isDouble = isdouble;
}

void Dices::setScore(int scor) {
    this->score = scor;
}

int Dices::getScore() {
    return this->score;
}

bool Dices::getIsDouble() {
    return this->isDouble;
}
