#include <iostream>
#include <utility>
#include "ButtonPlayer.h"

using namespace std;
using namespace render;

render::ButtonPlayer::ButtonPlayer(float sizeXButton, float sizeYButton, float posXButton, float posYButton,
                                   const sf::Font &font, std::string text, float posXText, float posYText) :
        button(sizeXButton, sizeYButton, posXButton, posYButton, font, std::move(text), posXText, posYText) {
    //this->rectangle = button.getRectangle();
}


Button render::ButtonPlayer::getButton() {
    return this->button;
}

vector<Cases *> render::ButtonPlayer::click(int x, int y, vector<Cases *> list_cases, sf::Vector2u size) {
    sf::FloatRect textRect = this->rectangle.getGlobalBounds();
    static ButtonPlayer *selectedText = nullptr;
    /*sf::RectangleShape rectangleShape{sf::Vector2f(10000, 10000)};
    rectangleShape.setFillColor(sf::Color::Red);
    rectangleShape.setPosition(size.x * 1.5, size.y * 0.5);*/
    if (textRect.contains(float(x), float(y))) {
        if (selectedText != nullptr) {
            this->rectangle.setFillColor(sf::Color::Black); // On remet sa couleur en jaune
            //selectedText->button.setRectangle(rectangleShape);
        }
        selectedText = this;
        this->rectangle.setFillColor(sf::Color::Green); // On change sa couleur en vert
        //selectedText->button.setRectangle(rectangleShape);
        list_cases = createAllCases(list_cases, sf::Vector2u(float(size.x), float(size.y) / 15));
    }
    return list_cases;
}

vector<Cases *> render::ButtonPlayer::createAllCases(vector<Cases *> list_cases, sf::Vector2u size) {
    const sf::Color color[8] = {
            sf::Color(0xFE90C9FF),
            sf::Color::Cyan,
            sf::Color::Magenta,
            sf::Color(0xE79C62FF),
            sf::Color::Red,
            sf::Color::Yellow,
            sf::Color::Green,
            sf::Color::Blue
    };
    /* Create all cases of properties */
    list_cases.clear(); // Delete all object

    int rep, count = 0;
    float posX_case = float(size.x) * 1.085, posY_case = float(size.y);
    for (auto c: color) {
        if (count == 4) {
            posY_case += 50;
            posX_case = float(size.x) * 1.085;
        }
        if (count == 0 || c == sf::Color::Blue) {
            rep = 2;
        } else {
            rep = 3;
        }
        for (int i = 0; i < rep; i++) {
            auto cases = new Cases(posX_case, posY_case, c);
            list_cases.push_back(cases);
            posX_case += float(size.x) * 0.072;
        }
        posX_case += float(size.x) * 0.03;
        count++;
    }
    posX_case = float(size.x) * 1.3, posY_case += 50;
    for (int i = 0; i < 2; ++i) {
        auto cases = new Cases(posX_case, posY_case, sf::Color(0xB8B8B8FF));
        list_cases.push_back(cases);
        posX_case += float(size.x) * 0.072;
    }
    posX_case += float(size.x) * 0.1;
    for (int i = 0; i < 4; ++i) {
        auto cases = new Cases(posX_case, posY_case, sf::Color(0x66666FF));
        list_cases.push_back(cases);
        posX_case += float(size.x) * 0.072;
    }
    return list_cases;
}