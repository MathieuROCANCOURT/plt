#include <iostream>
#include "Render.h"
#include "state/State.h"

using namespace std;
using namespace render;
using namespace state;


Render::Render(State & currentState) : currentState(currentState) {
    this->currentState.getNbplayer();
    this->window.create(sf::VideoMode(size.x * 2, size.y), "Monopoly");
    this->window.setVerticalSyncEnabled(true);
}

sf::RenderWindow &Render::getWindow() {
    return this->window;
}



