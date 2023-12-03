#include "ButtonPlayer.h"

using namespace std;
using namespace render;

render::ButtonPlayer::ButtonPlayer(float sizeXButton, float sizeYButton, float posXButton, float posYButton,
                                   const sf::Font &font, std::string text, float posXText, float posYText,
                                   int characterSize, sf::Color colorText, float thicknessButton, sf::Color buttonColor,
                                   sf::Color buttonOutline) : sizeXButton(sizeXButton),
                                                              sizeYButton(sizeYButton),
                                                              posXButton(posXButton),
                                                              posYButton(posYButton),
                                                              font(font),
                                                              text(std::move(text)),
                                                              posXText(posXText),
                                                              posYText(posYText),
                                                              characterSize(characterSize),
                                                              colorText(colorText),
                                                              thicknessButton(thicknessButton),
                                                              buttonColor(buttonColor),
                                                              buttonOutline(buttonOutline) {
    this->rectangle = sf::RectangleShape(sf::Vector2f(this->sizeXButton, this->sizeYButton));
    this->rectangle.setPosition(this->posXButton, this->posYButton);
    this->rectangle.setFillColor(sf::Color::Yellow);
    this->rectangle.setOutlineColor(sf::Color::Black);
    this->rectangle.setOutlineThickness(this->thicknessButton);

    this->textPlayer = sf::Text(this->text, this->font, this->characterSize);
    this->textPlayer.setFillColor(sf::Color::Black);
    this->textPlayer.setPosition(this->posXText, this->posYText);
}


sf::RectangleShape render::ButtonPlayer::getRectangle() {
    return this->rectangle;
}

sf::Text render::ButtonPlayer::getText() {
    return this->textPlayer;
}

vector<Cases *> render::ButtonPlayer::click(int x, int y, vector<Cases *> list_cases, sf::Vector2u size) {
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
    sf::FloatRect textRect = this->getRectangle().getGlobalBounds();
    static ButtonPlayer *selectedText = nullptr;
    if (textRect.contains(float(x), float(y))) {
        if (selectedText != nullptr) {
            selectedText->rectangle.setFillColor(sf::Color::Yellow); // On remet sa couleur en jaune
        }
        selectedText = this;
        selectedText->rectangle.setFillColor(sf::Color::Green); // On change sa couleur en vert

        /* Create all cases of properties */
        list_cases.clear(); // Delete all object

        int rep, count = 0;
        float posX_case = float(size.x) * 1.085, posY_case = float(size.y) / 15;
        for (auto c: color) {
            if (count == 4) {
                posY_case += float(size.y) / 12;
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
        posX_case = float(size.x) * 1.3, posY_case += float(size.y) / 12;
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
    }

    return list_cases;
}
