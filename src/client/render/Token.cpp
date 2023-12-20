#include <iostream>
#include <dirent.h>
#include "Token.h"

using namespace std;
using namespace render;

Token::Token(int obj) {
    struct dirent **namelist;
    int n;

    n = scandir("./../res/Tokens/", &namelist, 0, versionsort);
    if (n < 0) {
        perror("scandir");
    }
    string fileName = "./../res/Tokens/" + to_string(obj) + ".png";
    cout << fileName << endl;
    if (!this->texture.loadFromFile(fileName)) {
        cout << "Error load file boat." << endl;
    }
    this->sprite.setTexture(this->texture);
}

sf::Sprite Token::getSprite() {
    return this->sprite;
}

void Token::posInit(sf::Vector2f move) {
    this->sprite.move(move);
}

