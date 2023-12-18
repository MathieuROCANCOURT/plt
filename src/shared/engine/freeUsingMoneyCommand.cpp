//
// Created by alexis on 15/12/23.
//

#include "freeUsingMoneyCommand.h"


bool engine::freeUsingMoneyCommand::FreeByMoney(state::State &state) {
    state::Player* playerCurrent = state.getCurrentPlayer();
    if((playerCurrent->getMoney() - 500000) >= 0){
        payTheBank(state, 500000);
        playerCurrent->setGameStatus(state::PLAYINGFREE);
        state.modifyNbTurnInJail(0);
    }
}

void engine::freeUsingMoneyCommand::payTheBank(state::State &state, long long int valueMoney) {
    state::Player* playerCurrent = state.getCurrentPlayer();

    if((playerCurrent->getMoney() - valueMoney)<0){
        playerCurrent->setDebt(state::DEBT_BANK);
    }
    state.modifyMoney(*playerCurrent, -valueMoney);
}
