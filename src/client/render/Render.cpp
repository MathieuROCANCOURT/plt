#include <iostream>
#include "Render.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State &currentState) : currentState(currentState) {
    int nbPlayer;
    do {
        nbPlayer = this->drawInit();
        if (nbPlayer != 0) {
            this->drawChoosePlayer(nbPlayer);
        }
    } while (((int) currentState.getListPlayer().size() != nbPlayer) & (nbPlayer != 0));
    if (nbPlayer != 0) {
        this->currentState.getCurrentPlayer()->setMoney(300000);
        this->gameBoard = new GameBoard(this->currentState.getListPlayer());
        this->gameInfo = new GameInformation(this->gameBoard->getSizeBoard(), currentState.getListPlayer(),
                                             currentState.getBank());

        this->window.create(sf::VideoMode(this->gameBoard->getSizeBoard().x * 2, this->gameBoard->getSizeBoard().y),
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
    AllButtons listButton;
    for (int i = 2; i <= 6; i++) {
        listButton.addButton(
                new Button(130, 70, 30 + float(160 * (i - 2)), 80, to_string(i),
                           90 + float(160 * (i - 2)), 100));
    }
    listButton.addButton(new Button(130, 70, 30 + float(160 * 5), 80, "EXIT",
                                    72 + float(160 * 5), 100, sf::Color::Red));
    sf::Vector2i cursorPos;
    int nbPlayer = 0;

    while (windowInit.isOpen()) {
        windowInit.clear(sf::Color::White);
        sf::Event event{};
        while (windowInit.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    windowInit.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        cursorPos = sf::Mouse::getPosition(windowInit);

                        listButton.setFocus(cursorPos, event);
                        if (listButton.getFocus() != nullptr) {
                            string nbPlayerString = listButton.getFocus()->getText()->getStringText();
                            windowInit.close();
                            if (nbPlayerString == "EXIT") {
                                return 0;
                            }
                            nbPlayer = stoi(nbPlayerString);
                        }
                    }
                case sf::Event::MouseMoved:
                    cursorPos = sf::Mouse::getPosition(windowInit);
                    break;
                default:
                    break;
            }
        }

        menuText.draw(windowInit);
        listButton.draw(windowInit);

        windowInit.display();
    }
    return nbPlayer;
}

void Render::drawChoosePlayer(int nbPlayer) {
    sf::RenderWindow windowChoice;
    windowChoice.create(sf::VideoMode(1000, 200), "Choose token and name monopoly");
    windowChoice.setVerticalSyncEnabled(true);

    Text menuText = *new Text("Choose your name and your token.", 250, 20);
    Text userText = *new Text("Input username:", 75, 100, 20);
    TextField textField = *new TextField(120, 25, 250, 100, "");
    AllButtons listButtonToken = *new AllButtons();
    AllButtons listButtonAction = *new AllButtons();

    for (int i = 0; i < 6; i++) {
        listButtonToken.addButton(
                new Button(static_cast<state::Token>(i), 40, 40, 500 + float(60 * i), 80));
    }
    listButtonAction.addButton(new Button(100, 30, 30 + float(160 * 4), 160, "Next",
                                          55 + float(160 * 4), 160));
    listButtonAction.addButton(new Button(100, 30, 30 + float(160 * 5), 160, "EXIT",
                                          55 + float(160 * 5), 160, sf::Color::Red));
    sf::Vector2i cursorPos;


    while (windowChoice.isOpen()) {
        windowChoice.clear(sf::Color::White);
        sf::Event event{};
        while (windowChoice.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    windowChoice.close();
                    break;
                case sf::Event::MouseButtonPressed: {
                    cursorPos = sf::Mouse::getPosition(windowChoice);
                    textField.setFocus(cursorPos);

                    listButtonToken.setFocus(cursorPos, event);
                    listButtonAction.setFocus(cursorPos, event);

                    Button *buttonFocusAction = listButtonAction.getFocus();
                    if (buttonFocusAction != nullptr) {
                        /* Condition click button EXIT */
                        if (buttonFocusAction->getText()->getStringText() == "EXIT") {
                            windowChoice.close();
                            break;
                        }
                        if (buttonFocusAction->getText()->getStringText() == "Next") {
                            Button *buttonFocusToken = listButtonToken.getFocus();
                            buttonFocusAction->deselect();
                            if (buttonFocusToken != nullptr) {

                                string playerName = textField.getText()->getStringText();
                                state::Token playerToken = buttonFocusToken->getToken()->getObj();
                                currentState.addPlayer(*new Player(playerName, playerToken));
                                listButtonToken.removeButton(buttonFocusToken);
                                if (nbPlayer == (int) currentState.getListPlayer().size()) {
                                    windowChoice.close();
                                }
                                break;
                            }
                        }
                        string nbPlayerString = buttonFocusAction->getText()->getStringText();
                    }
                    break;
                }
                case sf::Event::MouseMoved:
                    cursorPos = sf::Mouse::getPosition(windowChoice);
                    break;
                default:
                    break;
            }
            if (event.type == sf::Event::MouseMoved) {
            }
            textField.handleInput(event);
        }

        menuText.draw(windowChoice);
        userText.draw(windowChoice);
        listButtonToken.draw(windowChoice);
        listButtonAction.draw(windowChoice);
        textField.draw(windowChoice);

        windowChoice.display();
    }
}


void Render::drawGame() {
    static sf::Event event{};
    static sf::Vector2i cursorPos;
    this->window.clear(sf::Color::White);

    /* Control event */
    while (this->window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                this->window.close();
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    cursorPos = sf::Mouse::getPosition(this->getWindow());
                }
                break;
            case sf::Event::MouseMoved:
                cursorPos = sf::Mouse::getPosition(this->window);
                break;
            default:
                break;
        }
    }
    /* Display window with elements */
    this->gameBoard->draw(this->window);
    this->gameInfo->draw(this->window, cursorPos, event);

    this->window.display();
}

void Render::debt(int player) {

}

Render::~Render() {
    delete this;
}
