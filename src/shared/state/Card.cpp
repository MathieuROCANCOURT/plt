#include "Card.h"

using namespace std;
using namespace state;


Card::Card(std::string text, bool freeJail, bool money, bool fctHostel, bool moveForwardTo, bool fromOthers, bool jail,
           int *args) : text(text), freeJail(freeJail), money(money), fctHostel(fctHostel), moveForwardTo(moveForwardTo), fromOthers(fromOthers), jail(jail) {


}

std::string Card::getText() {
    return this->text;
}