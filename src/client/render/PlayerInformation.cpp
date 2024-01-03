#include "PlayerInformation.h"
#include <utility>

using namespace std;
using namespace render;

PlayerInformation::PlayerInformation(vector<state::Player> listPlayer, sf::Vector2u sizeBoard) : listPlayer(
        std::move(listPlayer)), sizeBoard(sizeBoard) {
    int i = 0;
    for (auto player: this->listPlayer) {
        auto *button = new Button(95, 40, float(this->sizeBoard.x) + float(i) * 110 + 10, 5, player.getName(),
                                  float(this->sizeBoard.x) + float(i) * 110 + 20, 10);
        this->dictPlayer.emplace(button, player);
        this->listButtonPlayer->addButton(button);
        i++;
    }
    this->listCasesPlayer = new AllCases(this->sizeBoard, vector<state::Property *>{}, uint(this->sizeBoard.y * 0.15));
    this->textMoney = new Text("", float(this->sizeBoard.x * 1.1), float(this->sizeBoard.y * 0.09), 25,
                               sf::Color(0x288330FF));
}

std::map<Button *, state::Player> PlayerInformation::getDictPlayer() {
    return this->dictPlayer;
}

void PlayerInformation::draw(sf::RenderWindow &window, sf::Vector2i cursorPos, sf::Event event) {
    this->listButtonPlayer->setFocus(cursorPos, event);
    Button *test = this->listButtonPlayer->getFocus();
    if (test != nullptr) {
        this->listCasesPlayer->draw(window, cursorPos);
        this->textMoney->setStringText(to_string(this->dictPlayer.at(test).getMoney()));
        Token showToken = *new Token(this->dictPlayer.at(test).getToken());
        showToken.posMove(sf::Vector2f(float(this->sizeBoard.x * 1.03), float(this->sizeBoard.y * 0.09)));
        showToken.draw(window);
        window.draw(this->textMoney->getText());
    }
    this->listButtonPlayer->draw(window, cursorPos, event);
}
