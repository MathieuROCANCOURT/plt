#include "Token.h"
#include "config.h"

using namespace std;
using namespace render;

Token::Token(state::Token obj) : obj(obj) {
    string path = RES_DIR;

    string fileName = path + "Tokens/" + to_string(this->obj) + ".png";
    if (!this->texture.loadFromFile(fileName)) {
        perror("Error load file boat.\n");
    }
    this->sprite.setTexture(this->texture);
}

state::Token Token::getObj() {
    return this->obj;
}

sf::Sprite Token::getSprite() {
    return this->sprite;
}

void Token::posMove(sf::Vector2f move) {
    this->sprite.move(move);
}

void Token::posUpdate(state::Player player) {
    switch (player.getGameStatus()) {
        case state::PLAYINGFREE: {
            switch (player.getPosition()) {
                case 1 ... 10:
                    this->posMove(sf::Vector2f(positionCase[10 - player.getPosition()], positionCase[9]));
                    break;
                case 11 ... 20:
                    this->posMove(sf::Vector2f(positionCase[0], positionCase[20 - player.getPosition()]));
                    break;
                case 21 ... 30:
                    this->posMove(sf::Vector2f(positionCase[player.getPosition() - 21], positionCase[0]));
                    break;
                case 31 ... 40:
                    this->posMove(sf::Vector2f(positionCase[9], positionCase[player.getPosition() - 31]));
                    break;
                default:
                    perror("BAD VALUE position");
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

void Token::draw(sf::RenderWindow &window) {
    window.draw(this->sprite);
}

Token::~Token() = default;
