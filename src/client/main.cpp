#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>


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
        } else if (strcmp(argv[1], "render") == 0) {
            cout << "--- Render ---" << endl;

            State state;

            sf::RenderWindow window;
            sf::Texture plateauTexture;
            sf::Texture hatTexture;
            sf::Texture chaussureTexture;
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
            if (!hatTexture.loadFromFile("./../res/hat.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!chaussureTexture.loadFromFile("./../res/shoe.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!dogTexture.loadFromFile("./../res/dog.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!carTexture.loadFromFile("./../res/car.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!boatTexture.loadFromFile("./../res/boat.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }
            if (!ironTexture.loadFromFile("./../res/iron.png")) {
                cout << "Error load file." << endl;
                return EXIT_FAILURE;
            }

            // Charge fichier police
            sf::Font font;
            if (!font.loadFromFile("./../res/Police/ARIAL.TTF")) {
                cout << "Error load file ARIAL.TTF." << endl;
                return EXIT_FAILURE;
            }

            // Obtain size of picture
            sf::Vector2u size = plateauTexture.getSize();

            // Generate sprite
            sf::Sprite plateau(plateauTexture);
            sf::Sprite hat(hatTexture);
            sf::Sprite chaussure(chaussureTexture);
            sf::Sprite dog(dogTexture);
            sf::Sprite car(carTexture);
            sf::Sprite boat(boatTexture);
            sf::Sprite iron(ironTexture);

            // Move the picture
            hat.move(size.x - 80, size.y - 20);
            chaussure.move(size.x - 80, size.y - 55);
            dog.move(size.x - 80, size.y - 85);
            car.move(size.x - 35, size.y - 25);
            boat.move(size.x - 45, size.y - 55);
            iron.move(size.x - 35, size.y - 80);

            // création de la fenêtre
            window.create(sf::VideoMode(size.x * 2, size.y), "Monopoly");
            window.setVerticalSyncEnabled(true);

            // Add liste de texte
            vector<sf::Text> textes;
            vector<sf::RectangleShape> rectangles;
            for (int i = 0; i < liste.size(); i++) {
                sf::RectangleShape rectangle;
                rectangle.setSize(sf::Vector2f (95, 40));
                rectangle.setPosition(size.x + i * 110 + 10, 5);
                rectangle.setFillColor(sf::Color::Yellow);
                rectangle.setOutlineColor(sf::Color::Black);
                rectangle.setOutlineThickness(5);

                sf::Text texte;
                texte.setFont(font);
                texte.setString(liste[i]);
                texte.setCharacterSize(20);
                texte.setFillColor(sf::Color::Black);
                texte.setPosition(size.x + i * 110 + 20, 10);
                textes.push_back(texte);
                rectangles.push_back(rectangle);
            }

            sf::RectangleShape *selectedText = nullptr; // Pointeur vers le texte sélectionné

            // on fait tourner la boucle principale
            while (window.isOpen()) {
                // on gère les évènements
                sf::Event event{};
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }

                // effacement de la fenêtre en noir
                window.clear(sf::Color::White);

                // Voir clique souris gauche
                if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;

                    for (auto &rectangle: rectangles) {
                        sf::FloatRect textRect = rectangle.getGlobalBounds();
                        if (textRect.contains(x, y)) {
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
                    window.draw(rectangle);
                }
                for (auto &texte: textes) {
                    window.draw(texte);
                }

                sf::CircleShape square(20.f, 4);
                square.setFillColor(sf::Color::White);
                square.setOutlineColor(sf::Color{0xFF5D8FFF});
                square.setOutlineThickness(2);
                square.move(size.x * 1.5, size.y / 2);
                square.rotate(45);

                window.draw(square);

                window.draw(plateau);
                window.draw(chaussure);
                window.draw(hat);
                window.draw(dog);
                window.draw(car);
                window.draw(boat);
                window.draw(iron);
                window.display();
            }
        }

    } else {
        cout << "It works !" << endl;
    }

    return EXIT_SUCCESS;
}
