#include "PlayerInformation.h"

using namespace std;
using namespace render;

PlayerInformation::PlayerInformation(const vector<state::Player> &listPlayer, sf::Vector2u sizeBoard) {
    static int i = 0;
    for (auto player: listPlayer) {
        this->dictPlayer.emplace(new Button(95, 40, float(sizeBoard.x) + float(i) * 110 + 10, 5, player.getName(),
                                            float(sizeBoard.x) + float(i) * 110 + 20, 10), player.getMoney());
        i++;
    }
    this->listCasesPlayer = new AllCases(sizeBoard, uint(sizeBoard.y * 0.15));
    this->textMoney = new Text("", float(sizeBoard.x) * 1.1, float(sizeBoard.y) * 0.09, 25, sf::Color(0x288330FF));
}

std::map<Button *, long long> PlayerInformation::getDictPlayer() {
    return this->dictPlayer;
}

void PlayerInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos) {
    for (auto &dict: this->dictPlayer) {
        if (dict.first->getRectangle().getFillColor() == sf::Color::Green) {
            this->listCasesPlayer->draw(window, cursorPos);
            this->textMoney->setTextModify(to_string(dict.second));
            window.draw(this->textMoney->getText());
        }
        dict.first->draw(window);
    }
}
