//
// Created by ensea on 20/12/23.
//

#include "BuyPropertyCommand.h"


void engine::BuyPropertyCommand::buyTheProperty(state::State &state) {
    //state::Player* playerCurrent = state.getCurrentPlayer();
    //Achat de property (argument de la commande)
}

void engine::BuyPropertyCommand::execute(state::State &state) {
    buyTheProperty(state);
}
