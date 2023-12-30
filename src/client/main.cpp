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
            currentState.getBank().getBankProperties();
            currentState.addPlayer(*new Player("boat", BOAT));
            currentState.addPlayer(*new Player("car", CAR));
            currentState.addPlayer(*new Player("dog", DOG));
            currentState.addPlayer(*new Player("hat", HAT));
            currentState.addPlayer(*new Player("iron", IRON));
            currentState.addPlayer(*new Player("shoe", SHOE));

            Render *r;
            r = new Render(currentState);
            while (r->getWindow().isOpen()) {
                r->drawGame();
            }
            // Add card
            /*sf::Texture cardTexture;
            if (!cardTexture.loadFromFile("./../res/ChanceCards/win_rugby.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            sf::Sprite card(cardTexture);
            card.move(float(size.x) / 5, float(size.y) / 4);

            }*/
        }

    } else {
        cout << "It works !" << endl;
    }

    return EXIT_SUCCESS;
}
