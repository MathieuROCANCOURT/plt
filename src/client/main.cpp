// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

#include <state.h>
#include "render.h"
#include <cstring>
#include <iostream>

using namespace std;
using namespace state;
using namespace render;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "hello") == 0) {
            cout << "Bonjour le monde!" << endl;
        } else if (strcmp(argv[1], "state") == 0) {
            cout << R"(Veillez utiliser les commandes "make unittest" et "make code-coverage" depuis le dossier build)"
                 << endl;
        } else if (strcmp(argv[1], "render") == 0) {
            cout << "--- Render ---" << endl;

            state::State currentState = *new State();
            Render *r;
            r = new Render(currentState);
            while (r->getWindow().isOpen()) {
                sf::Event event{};
                while (r->getWindow().pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        r->getWindow().close();
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;

                    for (auto &rectangle: r->getGameInfo().getListButtonPlayer()) {
                        rectangle->click(x, y);
                    }
                }

                r->draw();
            }
            // Add liste de texte
            /*for (int i = 0; i < (int) liste.size(); i++) {
                ButtonPlayer buttonPlayer(95, 40, float(size.x) + float(i) * 110 + 10, 5, state.getFont(),
                                                liste[i], float(size.x) + float(i) * 110 + 20, 10);
                list_buttonPlayer.push_back(buttonPlayer);
            }

            sf::Texture cardTexture;
            if (!cardTexture.loadFromFile("./../res/ChanceCards/win_rugby.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            sf::Sprite card(cardTexture);
            card.move(float(size.x) / 5, float(size.y) / 4);

            sf::Text textBank("BANQUE", font, 50);
            textBank.move(float(size.x) * 1.35, float(size.y) / 3);

            // on fait tourner la boucle principale
            while (state.getWindow().isOpen()) {
                // on gère les évènements
                sf::Event event{};
                while (state.getWindow().pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        state.getWindow().close();
                    }
                }

                // effacement de la fenêtre en noir
                state.getWindow().clear(sf::Color::White);

                // Voir clique souris gauche
                if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;

                    for (auto rectangle: list_buttonPlayer) {
                        list_cases = rectangle.click(x, y, list_cases, size);
                    }
                }

                state.getWindow().draw(background);
                for (auto &c: list_cases) {
                    c->draw(state.getWindow());
                }
                for (auto &buttonPlayer: list_buttonPlayer) {
                    state.getWindow().draw(buttonPlayer.getRectangle());
                    state.getWindow().draw(buttonPlayer.getText());
                }

                state.getWindow().draw(plateau);
                state.getWindow().draw(shoe);
                state.getWindow().draw(hat);
                state.getWindow().draw(dog);
                state.getWindow().draw(car);
                state.getWindow().draw(boat);
                state.getWindow().draw(iron);

                state.getWindow().draw(card);
                state.getWindow().draw(textBank);
                state.getWindow().display();
            }*/
        }

    } else {
        cout << "It works !" << endl;
    }

    return EXIT_SUCCESS;
}
