#include "GameInformation.h"
#include "state/Player.h"

using namespace std;
using namespace render;

/*GameInformation::GameInformation(vector<state::Player> & listPlayer) : listPlayer(listPlayer) {
    for(auto i: listPlayer){
        listButton.push_back(Button(95, 40,))
    }
}*/


vector<Cases *> GameInformation::CreateCases(int clickwhere, vector<Cases *> listCases, sf::Vector2u size) {
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
    listCases.clear();
    /* Create all cases of properties */
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
            listCases.push_back(cases);
            posX_case += float(size.x) * 0.072;
        }
        posX_case += float(size.x) * 0.03;
        count++;
    }
    posX_case = float(size.x) * 1.3, posY_case += float(size.y) / 12;
    for (int i = 0; i < 2; ++i) {
        auto cases = new Cases(posX_case, posY_case, sf::Color(0xB8B8B8FF));
        listCases.push_back(cases);
        posX_case += float(size.x) * 0.072;
    }
    posX_case += float(size.x) * 0.1;
    for (int i = 0; i < 4; ++i) {
        auto cases = new Cases(posX_case, posY_case, sf::Color(0x66666FF));
        listCases.push_back(cases);
        posX_case += float(size.x) * 0.072;
    }

    return listCases;
}
GameInformation::GameInformation() {

}
