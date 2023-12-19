//
// Created by alexis on 15/12/23.
//

#include "InitGameCommand.h"


void engine::InitGameCommand::initPlayerInGame(state::State &state) {

    std::string names[] = {"A", "B", "C", "D", "E", "F"};

    if(nbPlayerToInit > 1 and nbPlayerToInit < 7){
        state.modifyNbPlayer(nbPlayerToInit);

        for(int i = 0; i < nbPlayerToInit ; i++){
            state::Player* newPlayer = new state::Player(names[i], (state::Token) i);
            state.addPlayer(*newPlayer);
        }
    }

}

void engine::InitGameCommand::execute(state::State &state) {
    initPlayerInGame(state);
}


