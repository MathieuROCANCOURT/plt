//
// Created by alexis on 15/12/23.
//

#include "InitGameCommand.h"


void engine::InitGameCommand::initPlayerInGame(state::State &state) {

    if(nbPlayerToInit > 1 and nbPlayerToInit < 7){
        state.modifyNbPlayer(nbPlayerToInit);

        /*for(int i = 0; i < nbPlayerToInit ; i++){

        }*/




    }

}

void engine::InitGameCommand::execute(state::State &state) {
    initPlayerInGame(state);
}


