#include "Token.h"
#include <iostream>
#include <dirent.h>

using namespace std;
using namespace render;

Token::Token(int obj) {
    struct dirent **namelist;
    int n;

    n = scandir("./../res/Tokens/", &namelist, 0, versionsort);
    if (n < 0) {
        perror("scandir\n");
    }
    string fileName = "./../res/Tokens/" + to_string(obj) + ".png";
    if (!this->texture.loadFromFile(fileName)) {
        perror("Error load file boat.\n");
    }
    this->sprite.setTexture(this->texture);
}

sf::Sprite Token::getSprite() {
    return this->sprite;
}

void Token::posMove(sf::Vector2f move) {
    this->sprite.move(move);
}

void Token::posModify(state::Player player) {
    switch (player.getGameStatus()) {
        case state::PLAYINGFREE: {
            switch (player.getPosition()) {
                case 1 ... 10:
                    this->posMove(sf::Vector2f(positionCase[player.getPosition() - 1], positionCase[9]));
                    break;
                case 11 ... 20:
                    this->posMove(sf::Vector2f(positionCase[player.getPosition() - 1], positionCase[9]));
                    break;
                case 21 ... 30:
                    this->posMove(sf::Vector2f(positionCase[player.getPosition() - 1], positionCase[9]));
                    break;
                case 31 ... 39:
                    this->posMove(sf::Vector2f(positionCase[player.getPosition() - 1], positionCase[9]));
                    break;
                default:
                    cout << "BAD VALUE position" << endl;
                    break;
            }
            break;
        }
        case state::PLAYINGJAIL:
            this->posMove(sf::Vector2f(30, 636));
            break;
        default:
            this->sprite.setColor(sf::Color::Transparent);
    }
}

