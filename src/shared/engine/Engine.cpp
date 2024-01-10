#include <random>
#include "Engine.h"


using namespace std;
using namespace state;


const state::State &engine::Engine::getState() const {
    return this->CurrentState;
}

engine::Engine::Engine() {
    this->CurrentState = State();
}

void engine::Engine::update(state::State &state) {
    this->currentCommands[0].execute(state);

}

void engine::Engine::addCommand(engine::Command *cmd) {
    this->currentCommands.push_back(*cmd);
}
