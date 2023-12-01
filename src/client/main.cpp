// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderStates.hpp>

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

            state::State currentState;
            sf::RenderWindow window;

            sf::Color color[8] = {
                    sf::Color(0xFE90C9FF),
                    sf::Color::Cyan,
                    sf::Color::Magenta,
                    sf::Color(0xE79C62FF),
                    sf::Color::Red,
                    sf::Color::Yellow,
                    sf::Color::Green,
                    sf::Color::Blue
            };

            sf::Texture plateauTexture;
            sf::Texture backgroundTexture;
            sf::Texture hatTexture;
            sf::Texture shoeTexture;
            sf::Texture dogTexture;
            sf::Texture carTexture;
            sf::Texture boatTexture;
            sf::Texture ironTexture;


            vector<std::string> liste = {"Player 1", "Player 2", "Player 3", "Player 4", "Player 5", "Player 6"};
            vector<Cases *> list_cases;
            vector<ButtonPlayer *> list_buttonPlayer;

            // Charger le fichier du plateau de l'image
            if (!plateauTexture.loadFromFile("./../res/Plateau_monopoly_resize.jpg")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            //if (!backgroundTexture.loadFromFile("/home/mathieu/Pictures/image background/325266.jpg")) {
            if (!backgroundTexture.loadFromFile("./../res/background.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            // Chargement des jetons
            if (!hatTexture.loadFromFile("./../res/Tokens/hat.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!shoeTexture.loadFromFile("./../res/Tokens/shoe.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!dogTexture.loadFromFile("./../res/Tokens/dog.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!carTexture.loadFromFile("./../res/Tokens/car.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!boatTexture.loadFromFile("./../res/Tokens/boat.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!ironTexture.loadFromFile("./../res/Tokens/iron.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }

            // Charge fichier police
            sf::Font font;

            // Obtain size of picture
            sf::Vector2u size = plateauTexture.getSize();

            // Generate sprite
            sf::Sprite plateau(plateauTexture);
            sf::Sprite background(backgroundTexture);
            sf::Sprite hat(hatTexture);
            sf::Sprite shoe(shoeTexture);
            sf::Sprite dog(dogTexture);
            sf::Sprite car(carTexture);
            sf::Sprite boat(boatTexture);
            sf::Sprite iron(ironTexture);

            // Move the picture
            hat.move(float(size.x) - 80, float(size.y) - 20);
            shoe.move(float(size.x) - 80, float(size.y) - 55);
            dog.move(float(size.x) - 80, float(size.y) - 85);
            car.move(float(size.x) - 35, float(size.y) - 25);
            boat.move(float(size.x) - 45, float(size.y) - 55);
            iron.move(float(size.x) - 35, float(size.y) - 80);

            // création de la fenêtre
            window.create(sf::VideoMode(size.x * 2, size.y), "Monopoly");
            window.setVerticalSyncEnabled(true);

            StateLayer state = StateLayer(currentState, window, font);

            // Add liste de texte
            for (int i = 0; i < (int) liste.size(); i++) {
                ButtonPlayer *buttonPlayer;
                buttonPlayer = new ButtonPlayer(95, 40, float(size.x) + float(i) * 110 + 10, 5, state.getFont(),
                                                liste[i], float(size.x) + float(i) * 110 + 20, 10);
                list_buttonPlayer.push_back(buttonPlayer);
            }

            sf::RectangleShape *selectedText = nullptr; // Pointeur vers le texte sélectionné

            sf::Texture cardTexture;
            if (!cardTexture.loadFromFile("./../res/ChanceCards/win_rugby.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            sf::Sprite card(cardTexture);
            card.move(float(size.x) / 5, float(size.y) / 4);

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

                    for (auto &rectangle: list_buttonPlayer) {
                        sf::FloatRect textRect = rectangle->getRectangle().getGlobalBounds();
                        if (textRect.contains(float(x), float(y))) {
                            if (selectedText != nullptr) {
                                selectedText->setFillColor(sf::Color::Yellow); // On remet sa couleur en jaune
                            }
                            selectedText = rectangle->changePointer();
                            selectedText->setFillColor(sf::Color::Green); // On change sa couleur en vert

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
                            break;
                        }
                    }
                }

                state.getWindow().draw(background);
                for (auto &c: list_cases) {
                    c->draw(state.getWindow());
                }
                for (auto &buttonPlayer: list_buttonPlayer) {
                    state.getWindow().draw(buttonPlayer->getRectangle());
                    state.getWindow().draw(buttonPlayer->getText());
                }

                state.getWindow().draw(plateau);
                state.getWindow().draw(shoe);
                state.getWindow().draw(hat);
                state.getWindow().draw(dog);
                state.getWindow().draw(car);
                state.getWindow().draw(boat);
                state.getWindow().draw(iron);

                state.getWindow().draw(card);
                state.getWindow().display();
            }
        }

    } else {
        cout << "It works !" << endl;
    }

    return EXIT_SUCCESS;
}
