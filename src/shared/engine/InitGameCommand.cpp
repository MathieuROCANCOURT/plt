#include "InitGameCommand.h"


void engine::InitGameCommand::initPlayerInGame(state::State &state) {

    //std::string names[] = {"A", "B", "C", "D", "E", "F"};

    if (this->nbPlayerToInit > 1 and this->nbPlayerToInit < 7) {
        state.modifyNbPlayer(this->nbPlayerToInit);

        for (int i = 0; i < this->nbPlayerToInit; i++) {
            state::Player *newPlayer = new state::Player(this->name[i], this->tabpion[i]);
            state.addPlayer(*newPlayer);
        }
    }

}

void engine::InitGameCommand::execute() {
    initPlayerInGame(state);
}

engine::InitGameCommand::InitGameCommand(int nbPlayer, std::vector<state::Token> pion,
                                              std::vector<std::string> nomPlayer, state::State &state,
                                              CommandTypeId typeID) : engine::Command(typeID) {
    this->nbPlayerToInit = nbPlayer;
    this->tabpion = pion;
    this->name = nomPlayer;
}










