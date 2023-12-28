#include "PlayerInformation.h"

using namespace std;
using namespace render;

PlayerInformation::PlayerInformation(const vector<state::Player>& listPlayer, sf::Vector2u sizeBoard) {
    static int i = 0;
    for (auto player: listPlayer){
        this->listButtonPlayer.emplace_back(new Button(95, 40, float(sizeBoard.x) + float(i) * 110 + 10, 5, player.getName(),
                                                       float(sizeBoard.x) + float(i) * 110 + 20, 10));
        i++;
    }
    this->listCasesPlayer = new AllCases(sizeBoard, uint(sizeBoard.y * 0.15));
}

std::vector<Button *> PlayerInformation::getListButtonPlayer() {
    return this->listButtonPlayer;
}

void PlayerInformation::draw(sf::RenderWindow & window, sf::Vector2i cursorPos) {
    for (auto buttonPlayer: this->listButtonPlayer){
        if (buttonPlayer->getRectangle().getFillColor() == sf::Color::Green) {
            this->listCasesPlayer->draw(window, cursorPos);
        }
        window.draw(buttonPlayer->getRectangle());
        window.draw(buttonPlayer->getText().getText());
    }
}
