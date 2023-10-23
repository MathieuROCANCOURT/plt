#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>


void testSFML() {
    sf::Texture texture;
}
// Fin test SFML

#include <state.h>
#include <cstring>

using namespace std;
using namespace state;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "hello") == 0) {
            cout << "Bonjour le monde!" << endl;
        } else if (strcmp(argv[1], "state") == 0) {
            cout << R"(Veillez utiliser les commandes "make unittest" et "make code-coverage" depuis le dossier build)"
                 << endl;
        } else if (strcmp(argv[1], "render") == 0){
            cout << "--- Render ---" << endl;

            State state;

            // création de la fenêtre
            sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

            sf::Texture plateauTexture;
            plateauTexture.loadFromFile("/home/mathieu/CLionProjects/plt/res/20231013_102244.jpg");
            sf::Sprite plateau(plateauTexture);
            sf::Vector2u size = plateauTexture.getSize();
            plateau.setOrigin(size.x / 2, size.y /2 );

            // on fait tourner la boucle principale
            while (window.isOpen()){
                // on gère les évènements
                sf::Event event{};
                while (window.pollEvent(event)){
                    if(event.type == sf::Event::Closed) {
                        window.close();
                    }
                }

                // effacement de la fenêtre en noir
                window.clear(sf::Color::Blue);
                window.draw(plateau);
                window.display();
            }

        } else {
            cout << "It works !" << endl;
        }
    }

    return 0;
}
