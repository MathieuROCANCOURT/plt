//
// Created by alexis on 15/12/23.
//

#include "freeUsingCardCommand.h"


void engine::freeUsingCardCommand::freeByCard(state::State &state) {

    state::Player* playerCurrent = state.getCurrentPlayer();

    int nbFreeJailCard = playerCurrent->getFreeJailCard();
    playerCurrent->setFreeJailCard(nbFreeJailCard -1);
    state.returnJailCard();

    playerCurrent->setGameStatus(state::PLAYINGFREE);
    state.modifyNbTurnInJail(0);

}

void engine::freeUsingCardCommand::execute(state::State &state) {
    freeByCard(state);
}
