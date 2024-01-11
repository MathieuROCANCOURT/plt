#include <random>
#include "Engine.h"


using namespace std;
using namespace state;


state::State &engine::Engine::getState()  {
    return this->CurrentState;
}

engine::Engine::Engine() {
    this->CurrentState = State();
}



void engine::Engine::addCommand(engine::Command *cmd) {
    this->currentCommands.push_back(cmd);
}

int engine::Engine::executeCommand() {
    if(this->currentCommands.empty()== true){
        return 0;
    }
    this->currentCommands.front()->execute(this->getState());
    this->currentCommands.erase(this->currentCommands.begin());
    return 0;
}
