#include <iostream>
#include "Render.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State &currentState) : currentState(currentState) {
    int nbPlayer = this->drawInit();
    if (nbPlayer != 0){
        this->drawChoosePlayer(nbPlayer);
        this->gameBoard = *new GameBoard(this->currentState.getNbPlayer());
        this->gameInfo = new GameInformation(this->gameBoard.getSizeBoard(), currentState.getListPlayer(),
                                             currentState.getBank());

        this->window.create(sf::VideoMode(this->gameBoard.getSizeBoard().x * 2, this->gameBoard.getSizeBoard().y),
                            "Monopoly");
        this->window.setVerticalSyncEnabled(true);
    }
}

state::State &Render::getCurrentState() const {
    return this->currentState;
}

GameInformation *Render::getGameInfo() {
    return this->gameInfo;
}

sf::RenderWindow &Render::getWindow() {
    return this->window;
}

int Render::drawInit() {
    sf::RenderWindow windowInit;
    windowInit.create(sf::VideoMode(1000, 200), "Menu monopoly");
    windowInit.setVerticalSyncEnabled(true);

    Text menuText = *new Text("Choose the number of player or exit.", 250, 20);
    vector<Button *> listButton;
    for (int i = 2; i <= 6; i++) {
        listButton.emplace_back(
                new Button(130, 70, 30 + float(160 * (i - 2)), 80, to_string(i),
                           90 + float(160 * (i - 2)), 100));
    }
    listButton.emplace_back(new Button(130, 70, 30 + float(160 * 5), 80, "EXIT",
                                       72 + float(160 * 5), 100, sf::Color::Red));
    sf::Vector2i cursorPos;
    int nbPlayer = 0;


    while (windowInit.isOpen()) {
        windowInit.clear(sf::Color::White);
        sf::Event event{};
        while (windowInit.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                windowInit.close();
            }
            if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                for (auto &rectangle: listButton) {
                    rectangle->click(x, y);
                    if (rectangle->getRectangle().getFillColor() == sf::Color::Green){
                        string nbPlayerString = rectangle->getText().getText().getString();
                        nbPlayer = stoi(nbPlayerString);
                        windowInit.close();
                    }
                }
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            cursorPos = sf::Mouse::getPosition(windowInit);
        }

        menuText.draw(windowInit);
        for (auto & rectangle: listButton) {
            rectangle->draw(windowInit);
        }
        windowInit.display();
    }
    return nbPlayer;
}

void Render::drawChoosePlayer(int nbPlayer) {
    sf::RenderWindow windowChoice;
    windowChoice.create(sf::VideoMode(1000, 200), "Choose token and name monopoly");
    windowChoice.setVerticalSyncEnabled(true);

    TextField textField = *new TextField(300, 30, 50, 100, "");
    vector<Player *> initPlayer;
    Text menuText = *new Text("Choose your name and your token.", 250, 20);
    vector<Button *> listButton;
    /*for (int i = 0; i < 6; i++) {
        listButton.emplace_back(
                new Button(130, 70, 30 + float(160 * (i - 2)), 80, to_string(i),
                           90 + float(160 * (i - 2)), 100));
    }
    listButton.emplace_back(new Button(130, 70, 30 + float(160 * 5), 80, "EXIT",
                                       72 + float(160 * 5), 100, sf::Color::Red));*/
    sf::Vector2i cursorPos;


    while (windowChoice.isOpen()) {
        windowChoice.clear(sf::Color::White);
        sf::Event event{};
        while (windowChoice.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                windowChoice.close();
                this->drawInit();
            }
            if (event.type == sf::Event::MouseButtonReleased and event.mouseButton.button == sf::Mouse::Left) {
                cursorPos = sf::Mouse::getPosition(windowChoice);
                textField.setFocus(cursorPos);
                /*for (auto &rectangle: listButton) {
                    rectangle->click(x, y);
                    if (rectangle->getRectangle().getFillColor() == sf::Color::Green){
                        string nbPlayerString = rectangle->getText().getText().getString();
                    }
                }*/
            }
        }

        if (event.type == sf::Event::MouseMoved) {
            cursorPos = sf::Mouse::getPosition(windowChoice);
        }
        textField.handleInput(event);

        menuText.draw(windowChoice);
        /*for (auto & rectangle: listButton) {
            rectangle->draw(windowChoice);
        }*/
        textField.draw(windowChoice);
        windowChoice.display();
    }
}


void Render::drawGame(const sf::Vector2i cursorPos) {
    this->window.clear(sf::Color::White);

    this->gameBoard.draw(this->window);
    this->gameInfo->draw(this->window, cursorPos);

    this->window.display();
}

void Render::debt(int player) {

}

Render::~Render() {
    delete this;
}
