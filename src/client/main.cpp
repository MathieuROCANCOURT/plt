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
            sf::Color color[8] = {sf::Color(0xFF5D8FFF),
                               sf::Color::Cyan,
                               sf::Color::Magenta,
                               sf::Color(0xE79C62FF),
                               sf::Color::Red,
                               sf::Color::Yellow,
                               sf::Color::Green,
                               sf::Color::Blue
                               };

            sf::RenderWindow window;
            sf::Texture plateauTexture;
            sf::Texture hatTexture;
            sf::Texture shoeTexture;
            sf::Texture dogTexture;
            sf::Texture carTexture;
            sf::Texture boatTexture;
            sf::Texture ironTexture;


            vector<std::string> liste = {"Player 1", "Player 2", "Player 3", "Player 4", "Player 5", "Player 6"};

            // Charger le fichier du plateau de l'image
            if (!plateauTexture.loadFromFile("./../res/Plateau_monopoly_resize.jpg")) {
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
            sf::Sprite hat(hatTexture);
            sf::Sprite shoe(shoeTexture);
            sf::Sprite dog(dogTexture);
            sf::Sprite car(carTexture);
            sf::Sprite boat(boatTexture);
            sf::Sprite iron(ironTexture);

            // Move the picture
            hat.move(float (size.x) - 80, float (size.y) - 20);
            shoe.move(float (size.x) - 80, float (size.y) - 55);
            dog.move(float (size.x) - 80, float (size.y) - 85);
            car.move(float (size.x) - 35, float (size.y) - 25);
            boat.move(float (size.x) - 45, float (size.y) - 55);
            iron.move(float (size.x) - 35, float (size.y) - 80);

            // création de la fenêtre
            window.create(sf::VideoMode(size.x * 2, size.y), "Monopoly");
            window.setVerticalSyncEnabled(true);

            StateLayer state = StateLayer(currentState, window, font);


            // Add liste de texte
            vector<sf::Text> texts;
            vector<sf::RectangleShape> rectangles;
            for (int i = 0; i < liste.size(); i++) {
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f (95, 40));
                rectangle.setPosition(float(size.x) + i * 110 + 10, 5);
                rectangle.setFillColor(sf::Color::Yellow);
                rectangle.setOutlineColor(sf::Color::Black);
                rectangle.setOutlineThickness(5);

                sf::Text text;
                text.setFont(state.getFont());
                text.setString(liste[i]);
                text.setCharacterSize(20);
                text.setFillColor(sf::Color::Black);
                text.setPosition(float(size.x) + i * 110 + 20, 10);
                texts.push_back(text);
                rectangles.push_back(rectangle);
            }

            sf::RectangleShape *selectedText = nullptr; // Pointeur vers le texte sélectionné

            sf::Texture cardTexture;
            if (!cardTexture.loadFromFile("./../res/ChanceCards/win_rugby.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            sf::Sprite card(cardTexture);
            card.move(float (size.x) / 5, float (size.y) / 4);

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

                    for (auto &rectangle: rectangles) {
                        sf::FloatRect textRect = rectangle.getGlobalBounds();
                        if (textRect.contains(float(x), float(y))) {
                            if (selectedText != nullptr) {
                                selectedText->setFillColor(sf::Color::Yellow); // On remet sa couleur en jaune
                            }
                            selectedText = &rectangle;
                            selectedText->setFillColor(sf::Color::Green); // On change sa couleur en vert

                            break;
                        }
                    }
                }


                for (auto &rectangle: rectangles) {
                    state.getWindow().draw(rectangle);
                }
                for (auto &texte: texts) {
                    state.getWindow().draw(texte);
                }

                for (auto c : color){
                    if (c == sf::Color(0xFF5D8FFF) | c == sf::Color::Blue){
                        sf::CircleShape squarePink(28.f, 4);
                        squarePink.setFillColor(sf::Color::White);
                        squarePink.setOutlineColor(c);
                        squarePink.setOutlineThickness(2);
                        squarePink.move(float(size.x) * 1.05, float(size.y) / 10);
                        squarePink.rotate(45);
                    }
                }
                sf::CircleShape squarePink(28.f, 4);
                squarePink.setFillColor(sf::Color::White);
                squarePink.setOutlineColor(color[0]);
                squarePink.setOutlineThickness(2);
                squarePink.move(float(size.x) * 1.05, float(size.y) / 10);
                squarePink.rotate(45);
                sf::CircleShape squarePink1(28.f, 4);
                squarePink1.setFillColor(sf::Color::White);
                squarePink1.setOutlineColor(color[0]);
                squarePink1.setOutlineThickness(2);
                squarePink1.move(float(size.x) * 1.13, float(size.y) / 10);
                squarePink1.rotate(45);

                sf::CircleShape squareBlueLight(28.f, 4);
                squareBlueLight.setFillColor(sf::Color::White);
                squareBlueLight.setOutlineColor(color[1]);
                squareBlueLight.setOutlineThickness(2);
                squareBlueLight.move(float(size.x) * 1.23, float(size.y) / 10);
                squareBlueLight.rotate(45);
                sf::CircleShape squareBlueLight1(28.f, 4);
                squareBlueLight1.setFillColor(sf::Color::White);
                squareBlueLight1.setOutlineColor(color[1]);
                squareBlueLight1.setOutlineThickness(2);
                squareBlueLight1.move(float(size.x) * 1.31, float(size.y) / 10);
                squareBlueLight1.rotate(45);
                sf::CircleShape squareBlueLight2(28.f, 4);
                squareBlueLight2.setFillColor(sf::Color::White);
                squareBlueLight2.setOutlineColor(color[1]);
                squareBlueLight2.setOutlineThickness(2);
                squareBlueLight2.move(float(size.x) * 1.39, float(size.y) / 10);
                squareBlueLight2.rotate(45);

                sf::CircleShape squarePurple(28.f, 4);
                squarePurple.setFillColor(sf::Color::White);
                squarePurple.setOutlineColor(color[2]);
                squarePurple.setOutlineThickness(2);
                squarePurple.move(float(size.x) * 1.49, float(size.y) / 10);
                squarePurple.rotate(45);
                sf::CircleShape squarePurple1(28.f, 4);
                squarePurple1.setFillColor(sf::Color::White);
                squarePurple1.setOutlineColor(color[2]);
                squarePurple1.setOutlineThickness(2);
                squarePurple1.move(float(size.x) * 1.57, float(size.y) / 10);
                squarePurple1.rotate(45);
                sf::CircleShape squarePurple2(28.f, 4);
                squarePurple2.setFillColor(sf::Color::White);
                squarePurple2.setOutlineColor(color[2]);
                squarePurple2.setOutlineThickness(2);
                squarePurple2.move(float(size.x) * 1.65, float(size.y) / 10);
                squarePurple2.rotate(45);

                sf::CircleShape squareOrange(28.f, 4);
                squareOrange.setFillColor(sf::Color::White);
                squareOrange.setOutlineColor(color[3]);
                squareOrange.setOutlineThickness(2);
                squareOrange.move(float(size.x) * 1.75, float(size.y) / 10);
                squareOrange.rotate(45);
                sf::CircleShape squareOrange1(28.f, 4);
                squareOrange1.setFillColor(sf::Color::White);
                squareOrange1.setOutlineColor(color[3]);
                squareOrange1.setOutlineThickness(2);
                squareOrange1.move(float(size.x) * 1.83, float(size.y) / 10);
                squareOrange1.rotate(45);
                sf::CircleShape squareOrange2(28.f, 4);
                squareOrange2.setFillColor(sf::Color::White);
                squareOrange2.setOutlineColor(color[3]);
                squareOrange2.setOutlineThickness(2);
                squareOrange2.move(float(size.x) * 1.91, float(size.y) / 10);
                squareOrange2.rotate(45);

                state.getWindow().draw(squarePink);
                state.getWindow().draw(squarePink1);
                state.getWindow().draw(squareBlueLight);
                state.getWindow().draw(squareBlueLight1);
                state.getWindow().draw(squareBlueLight2);
                state.getWindow().draw(squarePurple);
                state.getWindow().draw(squarePurple1);
                state.getWindow().draw(squarePurple2);
                state.getWindow().draw(squareOrange);
                state.getWindow().draw(squareOrange1);
                state.getWindow().draw(squareOrange2);

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
