#include "PlayerInformation.h"

using namespace std;
using namespace render;

PlayerInformation::PlayerInformation(const vector<state::Player> &listPlayer, sf::Vector2u sizeBoard) {
    int i = 0;
    for (auto player: listPlayer) {
        Button *button = new Button(95, 40, float(sizeBoard.x) + float(i) * 110 + 10, 5, player.getName(),
                                    float(sizeBoard.x) + float(i) * 110 + 20, 10);
        this->dictPlayer.emplace(button, player.getMoney());
        this->listButtonPlayer->addButton(button);
        i++;
    }
    this->listCasesPlayer = new AllCases(sizeBoard, uint(sizeBoard.y * 0.15));
    this->textMoney = new Text("", float(sizeBoard.x) * 1.1, float(sizeBoard.y) * 0.09, 25, sf::Color(0x288330FF));
}

std::map<Button *, long long> PlayerInformation::getDictPlayer() {
    return this->dictPlayer;
}

void PlayerInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos, sf::Event event) {
    this->listButtonPlayer->setFocus(cursorPos, event);
    Button *test = this->listButtonPlayer->getFocus();
    if (test != nullptr) {
        this->listCasesPlayer->draw(window, cursorPos);
        this->textMoney->setStringText(to_string(this->dictPlayer.at(test)));
        window.draw(this->textMoney->getText());
    }
    this->listButtonPlayer->draw(window);

    /*for (auto &dict: this->dictPlayer) {
        if (dict.first->getRectangle().getFillColor() == sf::Color::Green) {
            this->listCasesPlayer->draw(window, cursorPos);
            this->textMoney->setStringText(to_string(dict.second));
            window.draw(this->textMoney->getText());
        }
        dict.first->draw(window);
    }*/
}
